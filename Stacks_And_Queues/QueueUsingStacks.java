package Stacks_And_Queues;

import java.util.Stack;

public class QueueUsingStacks {
    private final Stack<Integer> master;
    private final Stack<Integer> child;

    private void FillChildFromMaster() {
        while (!master.isEmpty()) {
            child.push(master.pop());
        }
    }

    public QueueUsingStacks() {
        master = new Stack<>();
        child = new Stack<>();
    }

    public void push(int x) {
        master.push(x);
    }

    public int pop() {
        if (child.isEmpty()) {
            FillChildFromMaster();
        }
        return child.pop();
    }

    public int peek() {
        if (child.isEmpty())
            FillChildFromMaster();
        return child.peek();
    }

    public boolean empty() {
        return master.isEmpty() && child.isEmpty();
    }
}
