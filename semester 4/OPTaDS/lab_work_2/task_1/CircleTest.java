package org.example;

import org.junit.Test;

import static org.junit.Assert.*;

public class CircleTest {

    @Test
    public void Test1() {
        /* точки лежат на одной прямой, параллельной оси ОХ*/
        Triangle triangle = new Triangle(1, 1, 6, 1, 1);
        Circle circle = new Circle(triangle.getSide(), triangle);
        assertEquals(3.50000, circle.getCenter().x, 0.00001);
        assertEquals(2.4433756729740637, circle.getCenter().y, 0.00001);
        assertEquals(2.886751345948129, circle.getRadius(), 0.00001);
    }

    @Test
    public void Test2() {
        /* точки лежат на одной прямой, параллельной оси ОY*/
        Triangle triangle = new Triangle(0, -2, 0, 3, 0);
        Circle circle = new Circle(triangle.getSide(), triangle);
        assertEquals(1.4433756729740643, circle.getCenter().x, 0.00001);
        assertEquals(0.5, circle.getCenter().y, 0.00001);
        assertEquals(2.886751345948129, circle.getRadius(), 0.00001);
    }

    @Test
    public void Test3() {
        /* произвольные точки в разных координатных плоскостях*/
        Triangle triangle = new Triangle(-2, 8, 6, 1, 1);
        Circle circle = new Circle(triangle.getSide(), triangle);
        assertEquals(4.02072594216369, circle.getCenter().x, 0.00001);
        assertEquals(6.809401076758502, circle.getCenter().y, 0.00001);
        assertEquals(6.137317546507323, circle.getRadius(), 0.00001);
    }

    @Test
    public void Test4() {
        /* произвольные точки в одной координатной плоскости*/
        Triangle triangle = new Triangle(-2, 8, -6, 1, 0);
        Circle circle = new Circle(triangle.getSide(), triangle);
        assertEquals(-6.02072594216369, circle.getCenter().x, 0.00001);
        assertEquals(5.6547005383792515, circle.getCenter().y, 0.00001);
        assertEquals(4.654746681256314, circle.getRadius(), 0.00001);
    }
}