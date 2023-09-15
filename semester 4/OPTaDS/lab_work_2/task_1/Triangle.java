package org.example;

public class Triangle {
    private Point v1;
    private Point v2;
    private Point v3;
    private double side;

    public Triangle(double x1, double y1, double x2, double y2, int variant){
        this.v1 = new Point(x1, y1);
        this.v2 = new Point(x2, y2);
        this.side = Math.hypot(x1-x2, y1-y2);
        if (variant==1){
        double x3 = (x2-x1)*Math.cos(Math.toRadians(60))-(y2-y1)*Math.sin(Math.toRadians(60))+x1;
        double y3 = (x2-x1)*Math.sin(Math.toRadians(60))+(y2-y1)*Math.cos(Math.toRadians(60))+y1;
        this.v3 = new Point(x3, y3);} else{
            double x3 = (x2-x1)*Math.cos(Math.toRadians(-60))-(y2-y1)*Math.sin(Math.toRadians(-60))+x1;
            double y3 = (x2-x1)*Math.sin(Math.toRadians(-60))+(y2-y1)*Math.cos(Math.toRadians(-60))+y1;
        this.v3 = new Point(x3, y3);
        }
    }

    public Point getV1() {
        return v1;
    }

    public Point getV2() {
        return v2;
    }

    public Point getV3() {
        return v3;
    }

    public double getSide() {
        return side;
    }
}
