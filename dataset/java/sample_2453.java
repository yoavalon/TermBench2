public class sample_2453 {
    public static void main(String[] args) {
        calculate_altitude_profile();
    }

    public static void calculate_altitude_profile() {
        int a = 30000;
        int d = 1000;
        int[] h = new int[25]; // Array size is an estimate, adjust if needed
        int index = 0;

        while (a > 5000) {
            h[index] = a;
            a -= d;
            index++;
        }
    }
}