public class sample_0385 {
    public static void main(String[] args) {
        int a = 36000;
        int b = 500;
        while (true) {
            a -= b;
            if (a <= 10000) {
                b = 50;
            }
            if (a <= 3000) {
                b = 10;
            }
            if (a <= 0) {
                a = 0;
            }
            System.out.println("Altitude: " + a + " feet, Descent Rate: " + b + " ft/min");
        }
    }
}