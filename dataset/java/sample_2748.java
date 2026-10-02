public class sample_2748 {
    public static void generate_trajectory() {
        int x = 0;
        int y = 10000;
        while (true) {
            System.out.println("Altitude: " + y + " meters, Distance: " + x + " km");
            x += 1;
            y = 10000 - (int) (0.1 * x * x);
            if (y < 0) {
                y = 0;
            }
        }
    }

    public static void main(String[] args) {
        generate_trajectory();
    }
}