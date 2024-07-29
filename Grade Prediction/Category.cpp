#include "Category.h"

Category::Category(const string& name, double weight, int capacity)
    : name(name), weight(weight), numAssignments(0), capacity(capacity) {
    assignments = new Assignment[capacity];
}

Category::~Category() {
    delete[] assignments;
}

void Category::addAssignment(const Assignment& assignment) {
    if (numAssignments < capacity) {
        assignments[numAssignments++] = assignment;
    }
}

void Category::displaySummary() const {
    cout << "Name of category: " << name << endl;
    cout << "Total Weight: " << weight << "%" << endl;
    cout << "Assignments Completed: ";
    int completedAssignments = 0;
    for (int i = 0; i < numAssignments; ++i) {
        if (assignments[i].isCompleted()) {
            completedAssignments++;
        }
    }
    cout << completedAssignments << endl;
    cout << "Current Grade: " << calculateCurrentGrade() << "%" << endl;
    cout << "Assignments Remaining: " << numAssignments - completedAssignments << endl;
    cout << "Projected Grade on Remaining Assignments: " << calculateProjectedGrade() << "%" << endl;
}

void Category::displayDetails() const {
    cout << "Name of category: " << name << endl;
    for (int i = 0; i < numAssignments; ++i) {
        cout << assignments[i].getName() << ": "
            << assignments[i].getPointsScored() << " / "
            << assignments[i].getPointsPossible() << " = "
            << assignments[i].calculatePercentage() << "%" << endl;
    }
}

void Category::editAssignment(int index, double pointsScored) {
    if (index >= 0 && index < numAssignments) {
        assignments[index].setPointsScored(pointsScored);
    }
}

double Category::calculateCurrentGrade() const {
    double totalPointsScored = 0;
    double totalPointsPossible = 0;
    for (int i = 0; i < numAssignments; ++i) {
        if (assignments[i].isCompleted()) {
            totalPointsScored += assignments[i].getPointsScored();
            totalPointsPossible += assignments[i].getPointsPossible();
        }
    }
    return (totalPointsScored / totalPointsPossible) * 100;
}

double Category::calculateProjectedGrade() const {
    double totalPointsScored = 0;
    double totalPointsPossible = 0;
    for (int i = 0; i < numAssignments; ++i) {
        totalPointsScored += assignments[i].getPointsScored();
        totalPointsPossible += assignments[i].getPointsPossible();
    }
    return (totalPointsScored / totalPointsPossible) * 100;
}
