package Stacks_And_Queues;

import java.util.LinkedList;
import java.util.Queue;

public class StackUsingQueue {
    private final Queue<Integer> integers;

    public StackUsingQueue() {
        integers = new LinkedList<>();
    }

    public void push(int x) {
        integers.add(x);
        for (int i = 1; i < integers.size(); i++)
            integers.add(integers.remove());
    }

    public int pop() {
        if(empty())
            return -1;
        return integers.remove();
    }

    public int top() {
        if(empty())
            return -1;
        return integers.isEmpty() ? -1: integers.peek();
    }

    public boolean empty() {
        return integers.isEmpty();
    }
}
