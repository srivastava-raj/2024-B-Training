bool isFull()
{
    if (front == 0 && rear == MAX_SIZE - 1) {
        return true;
    }
    return false;
}