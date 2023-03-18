import java.util.*;

class vosrtri
{
    public static void main(String []args)
    {
        int MAXN = 1000001;
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        List<Integer> a = new ArrayList<Integer>();
        List<Integer> b = new ArrayList<Integer>();

        List<Integer> mx = new ArrayList<>(Collections.nCopies(MAXN, 0));
        List<Integer> my = new ArrayList<>(Collections.nCopies(MAXN, 0));

        for (int i=0; i<n; ++i) {
            int x = in.nextInt();
            int y = in.nextInt();
            a.add(x);
            b.add(y);
            mx.set(x, mx.get(x)+1);
            my.set(y, my.get(y)+1);
        }

        long answer = 0;

        for (int i=0; i<n; ++i) {
            answer += Long.valueOf(mx.get(a.get(i)) - 1) * (my.get(b.get(i)) - 1);
        }

        System.out.println(answer);
        in.close();
    }
};