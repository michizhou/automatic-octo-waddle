public class ThreeArrays { 
    public static void main(String[] args) {
        int n = args.length; 
        int[] a = new int[n]; 
        int[] b = new int[n+1]; 
        int[] c = b; 
        for (int i = 0; i < n; i++) 
            a[n-i-1] = Integer.parseInt(args[n-i-1]);
        for (int i = 0; i < n; i++) 
            b[i+1] = b[i] + a[i]; 
        for (int i = 0; i < n; i++) 
            c[i+1] = b[i] + c[i+1];
        
        System.out.println(a[0] + a[1] + "" + a[2]);
        System.out.println(b[0] + "" + b[1] + b[2] + b[3]);
        System.out.println(c[0] + "" + c[1] + c[2] + c[3]);
    } 
}