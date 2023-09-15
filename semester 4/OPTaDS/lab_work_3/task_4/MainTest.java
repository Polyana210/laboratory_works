package org.example;

import static org.junit.Assert.*;

public class MainTest {

    @org.junit.Test
    public void sort1() {
        String[] array1 = {"bababa", "saxaba", "baba", "nxjnbabasx", "sasx"};
        String[] res = {"sasx", "saxaba",  "baba", "nxjnbabasx", "bababa"};
        Comparator1 k = new Comparator1("ba");
        InsertionSort<String> c1 = new InsertionSort<>();
        c1.sort(array1,k);
        assertArrayEquals(res, array1 );
    }

    @org.junit.Test
    public void sort2() {
        String[] array1 = {"bababa", "saxaba", "baba", "nxjnbabasx", "sasx"};
        String[] res = {"baba", "sasx",  "bababa", "saxaba", "nxjnbabasx"};
        Comparator2 k = new Comparator2();
        CocktailSort<String> c1 = new CocktailSort<>();
        c1.sort(array1,k);
        assertArrayEquals(res, array1 );
    }


}