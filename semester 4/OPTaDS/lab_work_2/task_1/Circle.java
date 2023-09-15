package org.example;

public class Circle {
    private Point center;
    private double radius;

    public Circle(double Side_length, Triangle triangle){
        this.radius=Side_length/Math.sqrt(3);
        double x12 = triangle.getV1().getX()-triangle.getV2().getX();
        double x23 = triangle.getV2().getX()-triangle.getV3().getX();
        double x31 = triangle.getV3().getX()-triangle.getV1().getX();
        double y12 = triangle.getV1().getY()-triangle.getV2().getY();
        double y23 = triangle.getV2().getY()-triangle.getV3().getY();
        double y31 = triangle.getV3().getY()-triangle.getV1().getY();
        double z1 = Math.pow(triangle.getV1().getX(), 2)+ Math.pow(triangle.getV1().getY(), 2);
        double z2 = Math.pow(triangle.getV2().getX(), 2)+ Math.pow(triangle.getV2().getY(), 2);
        double z3 = Math.pow(triangle.getV3().getX(), 2)+ Math.pow(triangle.getV3().getY(), 2);
        double zx = y12*z3+y23*z1+y31*z2;
        double zy = x12*z3+x23*z1+x31*z2;
        double z = x12*y31 -y12*x31;
        double a = -zx/(2*z);
        double b = zy/(2*z);
        this.center = new Point(a, b);
    }
    public double getRadius() {
        return radius;
    }

    public Point getCenter() {
        return center;
    }

}
