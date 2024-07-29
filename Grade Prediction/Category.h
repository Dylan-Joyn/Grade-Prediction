#pragma once
#ifndef CATEGORY_H
#define CATEGORY_H

#include "Assignment.h"
#include <iostream>

using namespace std;

class Category {
private:
    string name;
    double weight;
    Assignment* assignments;
    int numAssignments;
    int capacity;

public:
    Category(const string& name = "", double weight = 0, int capacity = 100);
    ~Category();

    string getName() const {
       return name; }

    double getWeight() const {
        return weight; }

    void addAssignment(const Assignment& assignment);

    void displaySummary() const;
    void displayDetails() const;
    void editAssignment(int index, double pointsScored);
    double calculateCurrentGrade() const;
    double calculateProjectedGrade() const;
};

#endif



