package org.example;
import java.util.*;
import java.util.Scanner;
/*Дан ломаная, состоящая из N вершин. Для каждой вершины ломаной задаётся некое целое число,
а для каждого отрезка — операция (сложение или умножение). Количество вершин ломаной последовательно
 уменьшается по следующему правилу: выбирается некоторый отрезок и к числам,
 приписанных вершинам, которые соединены этим отрезком, применяется операция,
 заданная для выбранного отрезка; отрезок и его концы удаляются, а вместо них добавляется новая вершина,
 для которой задаётся число-результат выполненной операции. Процесс продолжается до тех пор, пока не
 останется только одна вершина. Для заданной ломанной найти такую последовательность отрезков,
 при которой число, полученное в последней вершине, будет максимальным.*/
public class Main {

    public static int maximum(int a, int b) {
        if (a > b) return a;
        else return b;
    }

    public static int f(int n, int[] A) {
        if (n == 1)return A[0];
        else return maximum(f(n - 1, A) + A[n-1], f(n - 1, A) * A[n-1]);
    }

    public static void way(int Num, int[] Number, int[] Rez) {
        System.out.print( " (");
        for (int i = 0; i < Num - 1; i++) {
            System.out.print(Number[i]);
            if (Rez[i] + Number[i + 1] == Rez[i + 1]) System.out.print(")- + -(");
            else System.out.print(")- * -(");
        }
        System.out.println(Number[Num - 1]+ ") ");
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String num;

        System.out.println("Введите количество вершин ломаной N:   ");
        int Num = (int) scanner.nextDouble();

        int[] Number = new int[Num];

        for (int i = 0; i < Num; i++) {
            int k = 1+i;
            System.out.println("Введите целое число для " + k + " вершины ");
            Number[i]=  (int) scanner.nextDouble();
        }

        int[] Rez = new int[Num];

        for (int i = 0; i < Num; i++) {
            Rez[i] = f(i + 1, Number);
        }
        System.out.println(" Максимальный результат в последней вершине при заданной последовательности: " + Rez[Num - 1]);
        System.out.println(" Последовательность отрезков, при которой число, полученное в последней вершине, будет максимальным:");
        way(Num, Number, Rez);

    }
}