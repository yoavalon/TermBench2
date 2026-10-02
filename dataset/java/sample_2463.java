public class sample_2463 {
    public static int sequence(int n) {
        int a = 0, b = 1;
        for (int _ = 0; _ < n; _++) {
            int temp = a;
            a = b;
            b = temp + b;
        }
        return a;
    }

    public static void main(String[] args) {
        System.out.println(sequence(10));
    }
}