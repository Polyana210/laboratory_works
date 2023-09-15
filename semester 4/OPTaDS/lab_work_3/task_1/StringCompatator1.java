package org.example;
import java.util.Comparator;

public class StringCompatator1 implements Comparator<String> {
    public String strs="ba";
    public int kol = 0;

    StringCompatator1(String s){
        strs = s;
    }

    /*sorting by the number of occurrences of a given substring S in a string*/
    public int compare(String s1, String s2) {
        kol++;
        int res_1 = podchet(s1, strs);
        int res_2 = podchet(s2, strs);
        if (res_1>res_2){return 1;}
        else if (res_1<res_2){return -1;}
        else return 0;
    }

    public int podchet(String s_1, String s_2){
        int index = 0, count = 0;
        while (true)
        {
            index = s_1.indexOf(s_2, index);
            if (index != -1)
            {
                count ++;
                index += s_2.length();
            }
            else {
                break;
            }
        }
        return count;
    }



}