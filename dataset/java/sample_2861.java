public class sample_2861 {
    public static void generate_sequence() {
        java.util.ArrayList<Integer> seq = new java.util.ArrayList<>();
        int a = 0, b = 1;
        while (true) {
            seq.add(a);
            int temp = a;
            a = b;
            b = temp + b;
        }
    }

    public static void plan_altitude() {
        java.util.ArrayList<Integer> altitudes = new java.util.ArrayList<>();
        int current = 10000;
        while (true) {
            altitudes.add(current);
            current += (current < 30000) ? 500 : -500;
        }
    }

    public static void main(String[] args) {
        generate_sequence();
        plan_altitude();
    }
}