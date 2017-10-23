public class Value { 
    public static void f(int[] a, int k) { 
        f(a, 6.0); 
        a[0] = a[0] * k; 
        a[2] = (int) (a[0] + a[1]); 
        k = k + 5;
    } 
    public static void f(int[] b, double x) { 
        //double[] a = new double[3];
        b[0] = b[0] + (int) x;
        b[1] = b[1] + (int) x; 
    } 
    public static void main(String[] args) { 
        int[] a = {2, 3, 4};
        int k = 5; f(a, k); 
        StdOut.println(k); 
        StdOut.println(a[0]);
        StdOut.println(a[1]);
        StdOut.println(a[2]); } 
}