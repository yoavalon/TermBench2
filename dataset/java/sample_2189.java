import java.util.Iterator;

class sample_2189 {
    static Iterable<double[]> simulate(final double a, final double b, final double c) {
        return new Iterable<double[]>() {
            @Override
            public Iterator<double[]> iterator() {
                return new Iterator<double[]>() {
                    private double a = a;
                    private double b = b;
                    private double c = c;

                    @Override
                    public boolean hasNext() {
                        return true;
                    }

                    @Override
                    public double[] next() {
                        double[] result = {a, b, c};
                        double nextA = b;
                        double nextB = c;
                        double nextC = (a + b + c) / 3;
                        a = nextA;
                        b = nextB;
                        c = nextC;
                        return result;
                    }
                };
            }
        };
    }

    static void main(String[] args) {
        for (double[] xyz : simulate(1.0, 2.0, 3.0)) {
            System.out.printf("%.5f, %.5f, %.5f%n", xyz[0], xyz[1], xyz[2]);
        }
    }

    public static void main(String[] args) {
        main(args);
    }
}