public class sample_2180 {
    public static void main(String[] args) {
        for (var x : cellularAutomata()) {
            System.out.println(java.util.Arrays.toString(x));
        }
    }

    public static Iterable<double[]> cellularAutomata() {
        return new Iterable<double[]>() {
            double a = 0.1, b = 0.2, c = 0.3, d = 0.4;

            public java.util.Iterator<double[]> iterator() {
                return new java.util.Iterator<double[]>() {
                    public boolean hasNext() {
                        return true;
                    }

                    public double[] next() {
                        double[] result = {a, b, c, d};
                        double nextA = b;
                        double nextB = c;
                        double nextC = d;
                        double nextD = a + b + c + d;
                        a = nextA;
                        b = nextB;
                        c = nextC;
                        d = nextD;
                        return result;
                    }
                };
            }
        };
    }
}