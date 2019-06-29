import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    // Arrays: Left Rotation
    // The first line contains two space-separated integers denoting the respective values of
    //(the number of integers) and (the number of left rotations you must perform).
    // The second line contains space-separated integers describing the respective
    // elements of the array's initial state.

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int k = in.nextInt();
        int a[] = new int[n];
        for(int a_i=0; a_i < n; a_i++){
            a[a_i] = in.nextInt();
        }
        int rounded = k%n;
        if(rounded == 0) {
            printArray(a);
            return;
        }
        int len = a.length;
        int[] b = new int[len];
        for(int j = 0; j < len; j++) {
           int c = j-rounded;
           if(c < 0) {
               c  = c+len;
           }
           b[c] = a[j];
        }
        printArray(b);
    }

    static void printArray(int[] a) {
        int len = a.length;
        for(int i= 0; i < len; i++) {
            System.out.print(a[i] + " ");
        }
    }
}
