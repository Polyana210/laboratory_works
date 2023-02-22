public class Task2{
    public static double factorial(int x) {
        int res = 1;
        for (int i=1; i<=x; i++){
        res*=i;}
        return res;
    }

    public static double expression(int x, double acc) {
        double result_func = Math.sin(x);
        System.out.println(result_func);
        double res = 0;
        for (int i=0; i>=0; i++){
        if (Math.abs(result_func - res)<=acc){
        return res;
        }
        res+=Math.pow(-1, i)*Math.pow(x, 2*i+1)/factorial(2*i+1);
        }
        return res;
    }

    public static void main(String[] args) {
        int a = Integer.parseInt(args[0]);
        double b = Double.parseDouble(args[1]);
        System.out.println(expression(a, b));
    }
}