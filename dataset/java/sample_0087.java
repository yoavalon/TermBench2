public class sample_0087 {
    public static void simulate() {
        int a = 10, b = 20, c = 30, d = 40;
        for (int _ = 0; _ < 5; _++) {
            int temp = a;
            a = b;
            b = c;
            c = d;
            d = temp + b + c + d;
        }
        System.out.println(a + " " + b + " " + c + " " + d);
    }

    public static void main(String[] args) {
        simulate();
    }
}