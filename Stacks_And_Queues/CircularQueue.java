package Stacks_And_Queues;

public class CircularQueue {
    private final int[] arr;
    private int head;
    private int tail;
    private final int capacity;
    private int counter;

    public CircularQueue(int k) {
        arr = new int[k];
        capacity = k;
        head = 0;
        tail = 0;
        counter = 0;
    }

    public boolean enQueue(int value) {
        if (isFull()) return false;
        arr[tail] = value;
        tail++;
        tail %= capacity;
        counter++;
        return true;
    }

    public boolean deQueue() {
        if (isEmpty()) return false;
        head++;
        head %= capacity;
        counter--;
        return true;
    }

    public int Front() {
        if (isEmpty()) return -1;
        return arr[head == 0 ? capacity - 1 : tail - 1];
    }

    public int Rear() {
        if (isEmpty()) return -1;
        return arr[tail == 0 ? capacity - 1 : tail - 1];
    }

    public boolean isEmpty() {
        return counter == 0;
    }

    public boolean isFull() {
        return counter == capacity;
    }
}
