/*Постройте окружность, описанную около равностороннего треугольника, если известно,
 что некоторые две его вершины расположены в точках (x1; y1) и (x2; y2).
 Рассмотреть все возможные варианты.*/

package org.example;

public class Runner {
    public static void main(String[] args) {
        double x1 = -2;
        double y1 = 8;
        double x2 = -6;
        double y2 = 1;
        Triangle triangle1 = new Triangle(x1, y1, x2, y2, 1);
        Triangle triangle2 = new Triangle(x1, y1, x2, y2, 0);
        Circle circle1 = new Circle(triangle1.getSide(), triangle1);
        System.out.println(circle1.getCenter());
        Circle circle2 = new Circle(triangle2.getSide(), triangle2);
        System.out.println("Два случая построения треугольника:");
        System.out.println("1) Треугольник с вершинами A "+ triangle1.getV1() + ", B " + triangle1.getV2()+ ", C " + triangle1.getV3());
        System.out.println(" Описанная окружность с центром в точке "+ circle1.getCenter() + " и радиусом " + circle1.getRadius());
        System.out.println("2) Треугольник с вершинами A "+ triangle2.getV1() + ", B " + triangle2.getV2()+ ", C " + triangle2.getV3());
        System.out.println(" Описанная окружность с центром в точке "+ circle2.getCenter() + " и радиусом " + circle2.getRadius());
    }
}

