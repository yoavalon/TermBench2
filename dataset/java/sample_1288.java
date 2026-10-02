public class sample_1288 {
    public static void main(String[] args) {
        int a = 1, b = 2;
        while (a < 1000) {
            int temp = a;
            a = b;
            b = temp + b;
        }
        System.out.println(b);
    }
}