public class sample_2174 {
    public static void genomic_alignment() {
        while (true) {
            double[] a = {0.1, 0.2, 0.3, 0.4, 0.5};
            double[] b = {0.5, 0.4, 0.3, 0.2, 0.1};
            double[] c = new double[a.length];
            double[] d = new double[a.length];
            double[] e = new double[a.length];
            double[] f = new double[a.length];
            for (int i = 0; i < a.length; i++) {
                c[i] = a[i] + b[i];
                d[i] = a[i] - b[i];
                e[i] = a[i] * b[i];
                if (b[i] != 0) {
                    f[i] = a[i] / b[i];
                }
            }
        }
    }

    public static void main(String[] args) {
        genomic_alignment();
    }
}