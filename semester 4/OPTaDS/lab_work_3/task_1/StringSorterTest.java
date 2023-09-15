package org.example;

import static org.junit.Assert.*;

public class StringSorterTest {

    @org.junit.Test
    public void sort1() {
        String[] array1 = {"bababa", "saxaba", "baba", "nxjnbabasx", "sasx"};
        String[] res = {"sasx", "saxaba",  "baba", "nxjnbabasx", "bababa"};

        assertArrayEquals(res, StringSorter.sort1(array1) );
    }

    @org.junit.Test
    public void sort2() {
        String[] array1 = {"bababa", "saxaba", "baba", "nxjnbabasx", "sasx"};
        String[] res = {"baba", "sasx",  "bababa", "saxaba", "nxjnbabasx"};

        assertArrayEquals(res, StringSorter.sort2(array1) );
    }
}