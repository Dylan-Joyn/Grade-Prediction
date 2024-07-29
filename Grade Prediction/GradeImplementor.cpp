#include "GradeImplementor.h"

GradeImplementor::GradeImplementor(int capacity)
    : numCategories(0), capacity(capacity) {
    categories = new Category[capacity];
}

GradeImplementor::~GradeImplementor() {
    delete[] categories;
}

void GradeImplementor::readFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Could not open file: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string categoryName, assignmentName;
        double pointsScored, pointsPossible;
        bool completed;

        ss >> categoryName >> assignmentName >> pointsScored >> pointsPossible >> completed;

        int categoryIndex = -1;
        for (int i = 0; i < numCategories; ++i) {
            if (categories[i].getName() == categoryName) {
                categoryIndex = i;
                break;
            }
        }
        if (categoryIndex == -1) {
            if (numCategories < capacity) {
                categories[numCategories++] = Category(categoryName, 0); // Add category with 0 weight initially
                categoryIndex = numCategories - 1;
            }
            else {
                continue;
            }
        }

        Assignment assignment(assignmentName, pointsPossible);
        if (completed) {
            assignment.setPointsScored(pointsScored);
            assignment.markCompleted();
        }
        categories[categoryIndex].addAssignment(assignment);
    }

    file.close();
}

void GradeImplementor::addCategory(const string& name, double weight) {
    if (numCategories < capacity) {
        categories[numCategories++] = Category(name, weight);
    }
}

void GradeImplementor::addAssignment(const string& categoryName, const Assignment& assignment) {
    for (int i = 0; i < numCategories; ++i) {
        if (categories[i].getName() == categoryName) {
            categories[i].addAssignment(assignment);
            break;
        }
    }
}

void GradeImplementor::displayCategorySummary() const {
    for (int i = 0; i < numCategories; ++i) {
        categories[i].displaySummary();
    }
}

void GradeImplementor::displayCategoryDetails(const string& categoryName) const {
    for (int i = 0; i < numCategories; ++i) {
        if (categories[i].getName() == categoryName) {
            categories[i].displayDetails();
            break;
        }
    }
}

void GradeImplementor::editAssignment(const string& categoryName, int index, double pointsScored) {
    for (int i = 0; i < numCategories; ++i) {
        if (categories[i].getName() == categoryName) {
            categories[i].editAssignment(index, pointsScored);
            break;
        }
    }
}

double GradeImplementor::predictedClassGrade() const {
    double totalWeight = 0;
    double weightedSum = 0;

    for (int i = 0; i < numCategories; ++i) {
        double currentGrade = categories[i].calculateCurrentGrade();
        weightedSum += currentGrade * categories[i].getWeight();
        totalWeight += categories[i].getWeight();
    }

    return weightedSum / totalWeight;
}


