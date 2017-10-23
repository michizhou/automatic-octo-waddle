public class MethodTester {
    private static void methodB(int[] c, int d) {
        c[0]++;
        d += 42;
    }
    private static int methodA(int[] a, int b) {
        methodB(a, b);
        a[0]++;
        return b/2;
    }
    public static void main(String[] args) {
        int[] arr = {8, 9, 10};
        int x = 1;
        x = methodA(arr, x);
        System.out.println(arr[0] + " " + x);
    }
}