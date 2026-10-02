import java.util.ArrayList;
import java.util.List;

public class sample_0947 {
    public static void f(int a, int b, int c) {
        List<int[]> d = new ArrayList<>();
        d.add(new int[]{a, b, c});
        while (true) {
            List<int[]> e = new ArrayList<>();
            for (int[] xyz : d) {
                int x = xyz[0], y = xyz[1], z = xyz[2];
                e.add(new int[]{x + y, y + z, z + x});
            }
            d = e;
        }
    }

    public static void main(String[] args) {
        f(1, 1, 1);
    }
}