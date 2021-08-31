import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class Reverse_an_array {
    public static int[] reverseArray(int arr[]) {
        int temp;
        for (int i = 0; i < arr.length / 2; i++) {
            temp = arr[i];
            arr[i] = arr[arr.length - 1 - i];
            arr[arr.length - 1 - i] = temp;
        }
        return arr;
    }

    public static void main(String args[]) {

        // Method 1:- use a function

        int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        for(int i=0;i<arr.length;i++){
        System.out.printf("%d ",arr[i]);
        }
        System.out.println();
        int arr_1[] = reverseArray(arr);
        for (int i = 0; i < arr_1.length; i++) {
        System.out.printf("%d ", arr_1[i]);
        }
        System.out.println();
        int arr2[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        for (int i = 0; i < arr2.length; i++) {
        System.out.printf("%d ", arr2[i]);
        }
        System.out.println();
        int arr_2[] = reverseArray(arr2);
        for (int i = 0; i < arr_2.length; i++) {
        System.out.printf("%d ", arr_2[i]);
        }
        System.out.println();

        //Method 2:- use list

        Integer[] arr3 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        for (int i = 0; i < arr.length; i++) {
            System.out.printf("%d ", arr[i]);
        }
        System.out.println();
        List<Integer> list = new ArrayList<>();
        list = Arrays.asList(arr3);
        Collections.reverse(list);
        System.out.println(list);
        list.forEach(System.out::print);
    }
}