public class sample_2781 {
    public static void transform_coordinates() {
        double a = 0, b = 0, c = 0;
        while (true) {
            double x = Math.sin(a);
            double y = Math.cos(b);
            double z = Math.tan(c);
            a += 0.1;
            b += 0.2;
            c += 0.3;
        }
    }

    public static void main(String[] args) {
        transform_coordinates();
    }
}