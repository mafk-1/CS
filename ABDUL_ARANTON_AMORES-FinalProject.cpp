#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// --- Function declarations ---
float calculateAverage(float g1, float g2, float g3, float g4, float g5);
float findHighest(float g1, float g2, float g3, float g4, float g5, string &subject);
float findLowest(float g1, float g2, float g3, float g4, float g5, string &subject);
int countPassing(float g1, float g2, float g3, float g4, float g5);
float getGrade(float average);
float inputGrade(string subject);

// --- Function implementations ---
float calculateAverage(float g1, float g2, float g3, float g4, float g5) {
    return (g1 + g2 + g3 + g4 + g5) / 5.0f;
}

float findHighest(float g1, float g2, float g3, float g4, float g5, string &subject) {
    float grades[5] = {g1, g2, g3, g4, g5};
    string subjects[5] = {"Math", "Science", "English", "History", "Art"};
    float highest = grades[0];
    subject = subjects[0];
    for (int i = 1; i < 5; i++) {
        if (grades[i] > highest) {
            highest = grades[i];
            subject = subjects[i];
        }
    }
    return highest;
}

float findLowest(float g1, float g2, float g3, float g4, float g5, string &subject) {
    float grades[5] = {g1, g2, g3, g4, g5};
    string subjects[5] = {"Math", "Science", "English", "History", "Art"};
    float lowest = grades[0];
    subject = subjects[0];
    for (int i = 1; i < 5; i++) {
        if (grades[i] < lowest) {
            lowest = grades[i];
            subject = subjects[i];
        }
    }
    return lowest;
}

int countPassing(float g1, float g2, float g3, float g4, float g5) {
    int count = 0;
    if (g1 >= 60) count++;
    if (g2 >= 60) count++;
    if (g3 >= 60) count++;
    if (g4 >= 60) count++;
    if (g5 >= 60) count++;
    return count;
}

float getGrade(float avg) {
    if (avg >= 96) return 1.0;
    if (avg >= 94) return 1.25;
    if (avg >= 92) return 1.5;
    if (avg >= 90) return 1.75;
    if (avg >= 88) return 2.0;
    if (avg >= 86) return 2.25;
    if (avg >= 84) return 2.5;
    if (avg >= 82) return 2.75;
    if (avg >= 80) return 3.0;
    return 5.0;
}

float inputGrade(string subject) {
    float g;
    while (true) {
        cout << "Enter " << subject << " grade (0-100): ";
        cin >> g;
        if (cin.fail() || g < 0 || g > 100) {
            cout << "Invalid input. Please enter a grade between 0 and 100.\n";
            cin.clear();
            cin.ignore(10000, '\n');
        } else {
            return g;
        }
    }
}

// --- Main program ---
int main() {
    string name, id, gradeLevel;
    int age;

    cout << "=== STUDENT PROFILE SETUP ===\n";
    cout << "Enter student name: ";
    getline(cin, name);
    cout << "Enter student ID: ";
    getline(cin, id);
    cout << "Enter student age: ";
    cin >> age;
    cin.ignore(); // clear newline
    cout << "Enter grade level: ";
    getline(cin, gradeLevel);

    cout << "\nProfile created successfully!\n\n";

    cout << "=== GRADE ENTRY ===\n";
    float math = inputGrade("Math");
    float science = inputGrade("Science");
    float english = inputGrade("English");
    float history = inputGrade("History");
    float art = inputGrade("Art");

    cout << "\nGrades recorded successfully!\n\n";

    // --- Calculations ---
    float avg = calculateAverage(math, science, english, history, art);
    string highSubj, lowSubj;
    float high = findHighest(math, science, english, history, art, highSubj);
    float low = findLowest(math, science, english, history, art, lowSubj);
    int passing = countPassing(math, science, english, history, art);
    float gwa = getGrade(avg);

    // Director’s List assumption: GWA <= 1.5 qualifies
    bool directorsList = (gwa <= 1.5);

    // --- Report Output ---
    cout << "========================================\n";
    cout << "STUDENT REPORT CARD\n";
    cout << "========================================\n\n";
    cout << "STUDENT INFORMATION:\n";
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
    cout << "Age: " << age << " years old" << endl;
    cout << "Grade Level: " << gradeLevel << endl << endl;

    cout << fixed << setprecision(1);
    cout << "SUBJECT GRADES:\n";
    cout << "Math: " << math << "%\n";
    cout << "Science: " << science << "%\n";
    cout << "English: " << english << "%\n";
    cout << "History: " << history << "%\n";
    cout << "Art: " << art << "%\n\n";

    cout << "GRADE STATISTICS:\n";
    cout << "Average Grade: " << avg << "%\n";
    cout << "Grade Equivalent (GWA): " << gwa << endl;
    cout << "Highest Grade: " << high << "% (" << highSubj << ")\n";
    cout << "Lowest Grade: " << low << "% (" << lowSubj << ")\n";
    cout << "Subjects Passing: " << passing << " out of 5\n\n";

    cout << "GWA: " << gwa << endl;
    cout << "Director's List Status: " 
         << (directorsList ? "YES (Congratulations!)" : "NO") << endl;

    return 0;
}

