public class Task1 {
    public static double expression(double a, double b, double c) {
        return a*a-b*b/(c*c+5);
    }

    public static void main(String[] args) {
        double a = Double.parseDouble(args[0]);
        double b = Double.parseDouble(args[1]);
        double c = Double.parseDouble(args[2]);
        System.out.println(expression(a, b, c));
    }
}