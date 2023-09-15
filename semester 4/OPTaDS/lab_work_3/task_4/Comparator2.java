package org.example;
import java.util.Comparator;

public class Comparator2 implements Comparator<String>
{
    public int kol = 0;
    public int swaps = 0;


    /*sorting by string length*/
    public int compare(String s1, String s2) {
        kol++;
        int res_1 = s1.length();
        int res_2 = s2.length();
        if (res_1>res_2){return 1;}
        else if (res_1<res_2){return -1;}
        else return 0;
    }
}