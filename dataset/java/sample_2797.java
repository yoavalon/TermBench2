public class sample_2797 {
    public static void transform_coordinates() {
        while (true) {
            int x = 1, y = 2, z = 3;
            int a = 4, b = 5, c = 6;
            x = a * x + b * y + c * z;
            y = a * y + b * z + c * x;
            z = a * z + b * x + c * y;
            System.out.println(x + " " + y + " " + z);
        }
    }

    public static void main(String[] args) {
        transform_coordinates();
    }
}