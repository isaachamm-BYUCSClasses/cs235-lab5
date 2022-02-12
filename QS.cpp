//
// Created by Isaac Hamm on 2/12/22.
//

#include "QS.h"

using namespace std;

QS::QS() {
}
QS::~QS() {};
void QS::sortAll();
int QS::medianOfThree(int left, int right);
int QS::partition(int left, int right, int pivotIndex);
string QS::getArray() const;
int QS::getSize() const;
bool QS::addToArray(int value);
bool QS::createArray(int capacity) {
    for (int i = 0; i < arraySize; ++i) {
        delete &array[i];
    }

    arraySize = capacity;
    int newArray[capacity];
    array = new int array[capacity];

}

void QS::clear() {
    for (int i = 0; i < arraySize; ++i) {
        delete &array[i];
    }

}