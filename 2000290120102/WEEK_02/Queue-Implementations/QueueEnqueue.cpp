void queueEnqueue(int data)
{
    // Check queue is full or not
    if (capacity == rear) {
        printf("\nQueue is full\n");
        return;
    }
     // Insert element at the rear
    else {
        queue[rear] = data;
        rear++;
    }
    return;
}