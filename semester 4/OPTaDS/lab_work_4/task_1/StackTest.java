package org.example;

import org.junit.Assert;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class StackTest {

    @Test
    void push_peek() {
        Stack stack = new Stack();
        stack.push("scdc");
        Assert.assertEquals("scdc", stack.peek());
    }

    @Test
    void isEmpty() {
        Stack stack = new Stack();
        Assert.assertEquals(true, stack.isEmpty());
        stack.push("scdc");
        Assert.assertEquals(false, stack.isEmpty());
    }

    @Test
    void pop() {
        Stack stack = new Stack();
        stack.push("scdc");
        Assert.assertEquals(false, stack.isEmpty());
        stack.pop();
        Assert.assertEquals(true, stack.isEmpty());
    }

}