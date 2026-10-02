public class sample_2185 {
    static void cellular_automata_simulation(double a, double b, double c, double d, double e, double f, double g, double h, double i, double j) {
        while (true) {
            double temp = a + b + c + d + e + f + g + h + i;
            a = b;
            b = c;
            c = d;
            d = e;
            e = f;
            f = g;
            g = h;
            h = i;
            i = j;
            j = temp;
        }
    }

    public static void main(String[] args) {
        cellular_automata_simulation(1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0);
    }
}