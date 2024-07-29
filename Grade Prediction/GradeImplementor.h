#pragma once
#ifndef GRADEIMPLEMENTOR_H
#define GRADEIMPLEMENTOR_H

#include "Category.h"
#include <fstream>
#include <sstream>

using namespace std;

class GradeImplementor {
private:
    Category* categories;
    int numCategories;
    int capacity;

public:
    GradeImplementor(int capacity = 10);
    ~GradeImplementor();

    void readFromFile(const string& filename);
    void addCategory(const string& name, double weight);
    void addAssignment(const string& categoryName, const Assignment& assignment);
    void displayCategorySummary() const;
    void displayCategoryDetails(const string& categoryName) const;
    void editAssignment(const string& categoryName, int index, double pointsScored);
    double predictedClassGrade() const;
};

#endif
