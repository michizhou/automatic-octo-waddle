public class Perfect
{
    public static int aliquot(int n) {
        int aliSum = 0;
        
        for (int i = 1; i < n; i++) {
            if (n % i == 0) {
                aliSum += i;
            }
        }
        return aliSum;
    }
    
    public static boolean isPerfect(int n) {
        int sum = aliquot(n);
        if (sum == n)
            return true;
    }
    
    public static boolean isAmicable(int n) {
        int sum = aliquot(n);
        if (aliquot(sum) == n && n != sum)
            return true;
    }
}