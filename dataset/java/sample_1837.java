public class sample_1837 {
    public static double track_sequence(int n) {
        double a = 0.0;
        double b = 1.0;
        for (int i = 0; i < n; i++) {
            double temp = a;
            a = b;
            b = temp + b;
        }
        return b;
    }

    public static void main(String[] args) {
        double result = track_sequence(10);
        System.out.println(result);
    }
}