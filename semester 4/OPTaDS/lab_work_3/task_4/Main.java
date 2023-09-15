package org.example;
import java.util.Arrays;
import java.util.Comparator;

public class Main
{
    public static void main(String[] args)
    {
        args = new String[]{"bababa", "saxaba", "baba", "nxjnbabasx", "sasx", "sxs"};
        print2(args);
        Comparator1 k = new Comparator1("ba");
        InsertionSort<String> c1 = new InsertionSort<>();
        c1.sort(args,k);
        System.out.println("sorting by the number of occurrences of a given substring S in a string".toUpperCase());
        print2(args);
        System.out.println("COMPARE:"+k.kol);
        System.out.println("SWAPS:"+c1.swaps);

        CocktailSort<String> c2 = new CocktailSort<>();
        Comparator2 m = new Comparator2();
        System.out.println("sorting by string length".toUpperCase());
        c2.sort(args, m);
        print2(args);
        System.out.println("COMPARE:"+m.kol);
        System.out.println("SWAPS:"+c2.swaps);
    }

    public static void print2(String[] array){
        for(int i = 0; i < array.length; i++) {
            System.out.println(array[i]);
        }
    }
}
