public class sample_0649 {
    public static void f(int x, int y, int z) {
        if (x <= 0 || y <= 0 || z <= 0) {
            return;
        }
        System.out.println("Altitude: " + x + ", Speed: " + y + ", Time: " + z);
        f(x - 1, y - 1, z - 1);
    }

    public static void main(String[] args) {
        f(10, 20, 30);
    }
}