// Grade Prediction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "GradeImplementor.h"

int main() {
    GradeImplementor tracker;

    tracker.readFromFile("assignments.txt");

    tracker.displayCategorySummary();
    cout << endl;

    tracker.displayCategoryDetails("Homework");
    cout << endl;
    tracker.displayCategoryDetails("Exams");
    cout << endl;
    tracker.displayCategoryDetails("Projects");

    cout << "Predicted Class Grade: " << tracker.predictedClassGrade() << "%" << endl;

    return 0;
}



