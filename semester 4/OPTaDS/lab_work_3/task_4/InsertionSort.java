package org.example;

import java.util.Comparator;

public class InsertionSort<T> implements Sort<T>{
    public int swaps=0;
    public void sort(T[] arr, Comparator<T> comp){
        for (int i = 1; i < arr.length; i++) {
            T key = arr[i];
            int j = i - 1;
            while (j >= 0 && comp.compare(arr[j], key)> 0) {
                arr[j + 1] = arr[j];
                swaps++;
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }
}
