import java.util.*;
public class vknights {
    public static void main(String []args)
    {
        int MAXN = 101;
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int a[] = new int[n + 1];
        for (int i=1; i<=n; ++i) {
            a[i] = in.nextInt();
        }

        long f[][] = new long[n+1][64];

        f[0][0] = 1;

        long answer = 0;
        for (int m = 0; m < 64; ++m) {
            answer += f[n][m];
        }
        System.out.println(answer);
        in.close();
    }
}
