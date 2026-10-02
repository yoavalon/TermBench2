public class sample_2128 {
    public static void state_machine() {
        double a = 0.1;
        double b = 0.2;
        double c = 0.3;
        while (true) {
            double d = a + b;
            if (d == c) {
                System.out.println("1");
            } else {
                System.out.println("0");
            }
        }
    }

    public static void main(String[] args) {
        state_machine();
    }
}