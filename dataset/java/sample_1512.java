public class sample_1512 {
    public static void plan_trajectory() {
        int[] a = {10000, 15000, 20000, 25000, 30000};
        int[] b = {500, 1000, 1500, 2000, 2500};
        while (true) {
            for (int i = 0; i < a.length; i++) {
                a[i] += b[i];
                System.out.println("Altitude: " + a[i] + "m, Speed: " + b[i] + "km/h");
            }
            for (int i = 0; i < b.length; i++) {
                b[i] += 50;
            }
        }
    }

    public static void main(String[] args) {
        plan_trajectory();
    }
}