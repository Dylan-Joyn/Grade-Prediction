#pragma once
#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <string>

using namespace std;

class Assignment {
private:
    string name;
    double pointsScored;
    double pointsPossible;
    bool completed;
    bool edited;

public:
    Assignment(const string& name = "", double pointsPossible = 0);

    string getName() const;
    double getPointsScored() const;
    double getPointsPossible() const;
    bool isCompleted() const;
    bool isEdited() const;

    void setPointsScored(double points);
    void setPointsPossible(double points);
    void markCompleted();

    double calculatePercentage() const;
};

#endif

