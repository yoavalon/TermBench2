public class sample_1847 {
    public static void plan_trajectory() {
        double a = 1000.0;
        double b = 0.0001;
        double c = 0.0002;
        for (int _ = 0; _ < 10000; _++) {
            a = a - b + c;
        }
        System.out.println(a);
    }

    public static void main(String[] args) {
        plan_trajectory();
    }
}