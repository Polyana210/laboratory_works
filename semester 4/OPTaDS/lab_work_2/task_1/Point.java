package org.example;

/**
 * Точка на плоскости
 * */
public class Point {
    protected double x;
    protected double y;

    /**
     * Создаёт точку с заданными координатами
     * @param x абсцисса точки
     * @param y ордината точки
     * */
    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    /**
     * Получает значение абсциссы точки
     * @return абсцисса точки
     */
    public double getX() {
        return x;
    }

    /**
     * Получает значение ординаты точки
     * @return ордината точки
     */
    public double getY() {
        return y;
    }

    @Override
    public String toString() {
        return "(" + x + "; " + y + ")";
    }
}

