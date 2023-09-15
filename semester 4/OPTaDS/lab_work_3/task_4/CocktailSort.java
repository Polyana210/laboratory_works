package org.example;

import java.util.Comparator;

public class CocktailSort<T> implements Sort<T>{
    public int swaps=0;
    public void sort(T[] arr, Comparator<T> comp){
        boolean swapped;
        do {
            swapped = false;
            for (int i =0; i<=  arr.length  - 2;i++) {
                if (comp.compare(arr[i], arr[i+1])==1) {
                    //test whether the two elements are in the wrong order
                    T temp = arr[i];
                    arr[i] = arr[i+1];
                    arr[i+1]=temp;
                    swaps++;
                    swapped = true;
                }
            }
            if (!swapped) {
                //we can exit the outer loop here if no swaps occurred.
                break;
            }
            swapped = false;
            for (int i= arr.length - 2;i>=0;i--) {
                if (comp.compare(arr[i], arr[i+1])== 1) {
                    T temp = arr[i];
                    arr[i] = arr[i+1];
                    arr[i+1]=temp;
                    swapped = true;
                    swaps++;
                }
            }
            //if no elements have been swapped, then the list is sorted
        } while (swapped);
    }
    }

