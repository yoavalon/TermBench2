public class sample_2707 {
    public static void transform_3d_coordinates() {
        while (true) {
            int a = 1, b = 2, c = 3;
            double r = Math.sqrt(a * a + b * b + c * c);
            a = (int) (a / r);
            b = (int) (b / r);
            c = (int) (c / r);
            int x = 0, y = 0, z = 0;
            x = x + a;
            y = y + b;
            z = z + c;
            System.out.println(x + " " + y + " " + z);
        }
    }

    public static void main(String[] args) {
        transform_3d_coordinates();
    }
}