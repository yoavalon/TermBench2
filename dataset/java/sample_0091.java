public class sample_0091 {
    public static void main(String[] args) {
        consensus_mechanism();
    }

    public static void consensus_mechanism() {
        int a = 1;
        int b = 0;
        for (int _ = 0; _ < 10; _++) {
            int temp = a;
            a = b;
            b = temp + b;
        }
    }
}