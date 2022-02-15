//
// Created by Isaac Hamm on 2/12/22.
//

#include "QS.h"
#include <string>
#include <sstream>

using namespace std;

void QS::sortAll() {
    if (!intVector.empty()) {
        partition(intVector.at(0), intVector.at(spotInVector), 0);
    }
}
int QS::medianOfThree(int left, int right) {
    if (intVector.empty() ||            //Runs through all the checks that would return -1
        left > right ||
        left < 0 ||
        right > vectorSize) {
        return -1;
    }
    int middle;
    int tmp;    //temp used for switching in bubble sort
    if (middle < left) {
        tmp = middle;
        middle = left;
        left = tmp;
    }
    if (middle > right) {
        tmp = middle;
        middle = right;
        right = tmp;
    }
    if (middle < left) {
        tmp = middle;
        middle = left;
        left = tmp;
    }

    return middle;
}

int QS::partition(int left, int right, int pivotIndex) {
    if (intVector.empty() ||            //runs through the checks to see if everything is good
        left < 0 ||
        right > spotInVector ||
        left > right ||
        left > pivotIndex ||
        pivotIndex > right) {
        return -1;
    }
    pivotIndex = medianOfThree(left, right);

    //move pivot to first position
    int tmp;
    tmp = intVector.at(pivotIndex);
    intVector.at(pivotIndex) = intVector.at(left);
    intVector.at(left) = tmp;

    int up;
    int down;
    up = left + 1;
    down = right;

    do {
        if (intVector.at(up) <= intVector.at(left) || intVector.at(up) == intVector.at(right)) {
            ++up;
        }
        if (intVector.at(down) >= intVector.at(left) || intVector.at(down) == intVector.at(left + 1)) {
            --down;
        }
        if (intVector.at(up) > intVector.at(down)) {
            tmp = intVector.at(up);
            intVector.at(up) = intVector.at(down);
            intVector.at(down) = tmp;
        }
    } while (down < up);
    pivotIndex = down;

    return pivotIndex;
}

string QS::getArray() const {
    stringstream ss;
    string vectorString;

    if (intVector.empty()) {
        return vectorString;
    }

    for (int i = 0; i < spotInVector; ++i) {
        ss << intVector.at(i);
        if (i != spotInVector - 1) {
            ss << ", ";
        }
    }
    ss << endl;

    vectorString = ss.str();
    cout << vectorString;

    return vectorString;
}
int QS::getSize() const {
    return intVector.size();
}
bool QS::addToArray(int value) {
    if (spotInVector < vectorSize) {
        intVector.at(spotInVector) = value;
        ++spotInVector;
        return true;
    }
    else {
        return false;
    }
}
bool QS::createArray(int capacity) {
    if (!intVector.empty()) {
        intVector.clear();
    }
    for (int i = 0; i < capacity; ++i) {
        intVector.push_back(0);
    }
    vectorSize = capacity;
    spotInVector = 0;

    return true;
}

void QS::clear() {
    if (!intVector.empty()) {
        intVector.clear();
    }
// I don't think these are necessary, but just in case
//    arraySize = 0;
//    spotInVector = 0;
}