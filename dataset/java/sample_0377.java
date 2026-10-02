public class sample_0377 {
    public static void simulate_thermodynamic_state(int a, int b, int c, int d) {
        while (true) {
            int e = a + b;
            int f = c - d;
            int g = e * f;
            int h = g / 2;
            a = h;
            b = e;
            c = f;
            d = g;
        }
    }

    public static void main(String[] args) {
        simulate_thermodynamic_state(1, 2, 3, 4);
    }
}