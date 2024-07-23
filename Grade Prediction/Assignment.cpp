#include "Assignment.h"
Assignment::Assignment(const string& name = "", double pointsPossible = 0) : name(name), pointsScored(0), pointsPossible(pointsPossible), completed(false), edited(false) {}

string Assignment::getName() const {
	return name;
}
double Assignment::getPointsScored() const {
	return pointsScored;
}
double Assignment::getPointsPossible() const {
	return pointsPossible;
}
bool Assignment::isCompleted() const {
	return completed;
}
bool Assignment::isEdited() const {
	return edited;
}

void Assignment::setPointsScored(double points) {
	pointsScored = points;
	completed = true;
	edited = true;
}
void Assignment::setPointsPossible(double points) {
	pointsPossible = points;
}
void Assignment::markCompleted() {
	completed = true;
}

double Assignment::calculatePercentage() const {
	return (pointsScored / pointsPossible) * 100;
}