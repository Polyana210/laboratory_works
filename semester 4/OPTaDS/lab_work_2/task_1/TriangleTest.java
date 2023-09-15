package org.example;

import org.junit.Test;

import static org.junit.Assert.*;

public class TriangleTest {

    @Test
    public void Test1() {
        /* точки лежат на одной прямой, параллельной оси ОХ*/
        double x1 = 0;
        double y1 = 0;
        double x2 = 6;
        double y2 = 0;
        Triangle triangle1 = new Triangle(x1, y1, x2, y2, 1);
        Triangle triangle2 = new Triangle(x1, y1, x2, y2, 0);
        assertEquals(3, triangle1.getV3().x, 0.00001);
        assertEquals(5.196152422706632, triangle1.getV3().y, 0.00001);
        assertEquals(3, triangle2.getV3().x, 0.00001);
        assertEquals(-5.196152422706632, triangle2.getV3().y, 0.00001);
        assertEquals(6, triangle1.getSide(), 0.00001);
    }

    @Test
    public void Test2() {
        /* точки лежат на одной прямой, параллельной оси ОY*/
        double x1 = 0;
        double y1 = 6;
        double x2 = 6;
        double y2 = 6;
        Triangle triangle1 = new Triangle(x1, y1, x2, y2, 1);
        Triangle triangle2 = new Triangle(x1, y1, x2, y2, 0);
        assertEquals(3, triangle1.getV3().x, 0.00001);
        assertEquals(11.196152422706632, triangle1.getV3().y, 0.00001);
        assertEquals(3, triangle2.getV3().x, 0.00001);
        assertEquals(0.803847577293368, triangle2.getV3().y, 0.00001);
        assertEquals(6, triangle1.getSide(), 0.00001);
    }
    @Test
    public void Test3() {
        /* произвольные точки в разных координатных плоскостях*/
        double x1 = 1;
        double y1 = 4;
        double x2 = -2;
        double y2 = -8;
        Triangle triangle1 = new Triangle(x1, y1, x2, y2, 1);
        Triangle triangle2 = new Triangle(x1, y1, x2, y2, 0);
        assertEquals(9.892304845413264, triangle1.getV3().x, 0.00001);
        assertEquals(-4.598076211353318, triangle1.getV3().y, 0.00001);
        assertEquals(-10.892304845413264, triangle2.getV3().x, 0.00001);
        assertEquals( 0.5980762113533142, triangle2.getV3().y, 0.00001);
        assertEquals(12.36931687685298, triangle1.getSide(), 0.00001);
    }

    @Test
    public void Test4() {
        /* произвольные точки в одной координатной плоскости*/
        double x1 = -4;
        double y1 = 4;
        double x2 = -2;
        double y2 = 8;
        Triangle triangle1 = new Triangle(x1, y1, x2, y2, 1);
        Triangle triangle2 = new Triangle(x1, y1, x2, y2, 0);
        assertEquals(-6.464101615137754, triangle1.getV3().x, 0.00001);
        assertEquals(7.732050807568878, triangle1.getV3().y, 0.00001);
        assertEquals(0.4641016151377544, triangle2.getV3().x, 0.00001);
        assertEquals( 4.267949192431123, triangle2.getV3().y, 0.00001);
        assertEquals(4.47213595499958, triangle1.getSide(), 0.00001);
    }
}