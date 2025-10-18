template <typename T>
ArrayQueue<T>::ArrayQueue(int i) {
    if (i <= 0)
        throw string("Invalid max size for queue");

    maxSize = i;
    buffer = new T[maxSize];
    this->length = 0;
    frontIndex = 0;
    backIndex = -1;
}

template <typename T>
ArrayQueue<T>::ArrayQueue(const ArrayQueue<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayQueue<T>& ArrayQueue<T>::operator=(const ArrayQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayQueue<T>::~ArrayQueue() {
    clear();
}

template <typename T>
void ArrayQueue<T>::copy(const ArrayQueue<T>& copyObj) {
    maxSize = copyObj.maxSize;
    buffer = new T[maxSize];
    this->length = copyObj.length;
    frontIndex = copyObj.frontIndex;
    backIndex = copyObj.backIndex;

    for (int i = 0; i < copyObj.length; i++) {
        int idx = (copyObj.frontIndex + i) % maxSize;
        buffer[idx] = copyObj.buffer[idx];
    }
}

template <typename T>
void ArrayQueue<T>::clear() {
    delete[] buffer;
    buffer = nullptr;
    this->length = 0;
    frontIndex = 0;
    backIndex = -1;
    maxSize = 0;
}

template <typename T>
void ArrayQueue<T>::enqueue(const T& elem) {
    if (isFull())
        throw string("enqueue on full queue");


    backIndex = (backIndex + 1) % maxSize;
    buffer[backIndex] = elem;
    this->length++;
}

template <typename T>
void ArrayQueue<T>::dequeue() {
    if (isEmpty())
        throw string("dequeue on empty queue");

    frontIndex = (frontIndex + 1) % maxSize;
    this->length--;

    
    if (isEmpty()) {
        frontIndex = 0;
        backIndex = -1;
    }
}

template <typename T>
T ArrayQueue<T>::front() const {
    if (isEmpty())
        throw string("front on empty queue");
    return buffer[frontIndex];
}

template <typename T>
T ArrayQueue<T>::back() const {
    if (isEmpty())
        throw string("back on empty queue");
    return buffer[backIndex];
}


