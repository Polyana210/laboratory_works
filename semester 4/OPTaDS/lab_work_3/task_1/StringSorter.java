package org.example;
import java.util.Arrays;

public  class StringSorter {
    public String[] sorted_array_1;
    public String[] sorted_array_2;
    public static void main(String[] args) {
       String[] array = {"bababa", "saxaba", "baba", "nxjnbabasx", "sasx"};
        System.out.println("the original set of words".toUpperCase());
        for(int i = 0; i < array.length; i++) {
            System.out.println(array[i]);
        }
        sort1(array);
        sort2(array);
    }

    public static String[] sort1(String[] array){
        System.out.println("sorting by the number of occurrences of a given substring S in a string".toUpperCase());
        StringCompatator1 Comp1 = new StringCompatator1("ba");
        Arrays.sort(array, Comp1);
        for(int i = 0; i < array.length; i++) {
            System.out.println(array[i]);
        }
        System.out.println("COMPARE:" +Comp1.kol);
        return array;
    }

    public static String[] sort2(String[] array){
        System.out.println("sorting by string length".toUpperCase());
        StringCompatator2 Comp2 = new StringCompatator2();
        Arrays.sort(array, Comp2);
        for(int i = 0; i < array.length; i++) {
            System.out.println(array[i]);
        }
        System.out.println("COMPARE:" +Comp2.kol);
        return array;
    }
}