public class sample_2710 {
    public static void main(String[] args) {
        for (double[] state : simulate()) {
            System.out.println(java.util.Arrays.toString(state));
        }
    }

    public static Iterable<double[]> simulate() {
        return new Iterable<double[]>() {
            @Override
            public java.util.Iterator<double[]> iterator() {
                return new java.util.Iterator<double[]>() {
                    double x = 1.0, y = 0.0, z = 0.0;

                    @Override
                    public boolean hasNext() {
                        return true; // Non-terminating
                    }

                    @Override
                    public double[] next() {
                        double[] currentState = {x, y, z};
                        double nextX = y;
                        double nextY = z;
                        double nextZ = 3.9 * x * (1 - x) + z;
                        x = nextX;
                        y = nextY;
                        z = nextZ;
                        return currentState;
                    }
                };
            }
        };
    }
}