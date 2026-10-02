public class sample_0347 {
    public static void main(String[] args) {
        simulate();
    }

    public static void simulate() {
        double[] data = {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9};
        while (true) {
            for (int i = 0; i < data.length; i++) {
                data[i] = (data[i] + 0.01) % 1.0;
                for (double d : data) {
                    System.out.print(d + " ");
                }
                System.out.println();
            }
        }
    }
}