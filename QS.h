//
// Created by Isaac Hamm on 2/12/22.
//

#ifndef LAB5_QS_H
#define LAB5_QS_H

#include "QSInterface.h"

class QS: public QSInterface {

private:
    int array[5];
    int arraySize;

public:
    QS() {};
    ~QS() {};
    void sortAll();
    int medianOfThree(int left, int right);
    int partition(int left, int right, int pivotIndex);
    string getArray() const;
    int getSize() const;
    bool addToArray(int value);
    bool createArray(int capacity);
    void clear();

};


#endif //LAB5_QS_H
