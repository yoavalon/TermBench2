public class sample_2184 {
    public static void track_sequence(int precision) {
        double a = 0.0;
        double b = 1.0;
        while (true) {
            double temp = a;
            a = b;
            b = temp + b / precision;
            System.out.printf("%." + precision + "f%n", a);
        }
    }

    public static void main(String[] args) {
        track_sequence(10);
    }
}