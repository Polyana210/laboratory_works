package org.example;

import org.junit.Assert;

import static org.junit.jupiter.api.Assertions.*;

class QueueTest {

    @org.junit.jupiter.api.Test
    void dequeue() {
        Queue q = new Queue(5);
        q.enqueue("1");
        q.enqueue("2");
        Assert.assertEquals("1", q.peek());
        q.dequeue();
        Assert.assertEquals("2", q.peek());
    }

    @org.junit.jupiter.api.Test
    void enqueue() {
        Queue q = new Queue(5);
        q.enqueue("1");
        Assert.assertEquals("1", q.peek());
    }

    @org.junit.jupiter.api.Test
    void size() {
        Queue q = new Queue(5);
        q.enqueue("1");
        q.enqueue("2");
        Assert.assertEquals(2, q.size());
    }

    @org.junit.jupiter.api.Test
    void isEmpty() {
        Queue q = new Queue(5);
        Assert.assertEquals(true, q.isEmpty());
        q.enqueue("1");
        Assert.assertEquals(false, q.isEmpty());
    }

    @org.junit.jupiter.api.Test
    void isFull() {
        Queue q = new Queue(5);
        q.enqueue("1");
        q.enqueue("1");
        q.enqueue("1");
        q.enqueue("1");
        Assert.assertEquals(false, q.isFull());
        q.enqueue("1");
        Assert.assertEquals(true, q.isFull());
    }
}