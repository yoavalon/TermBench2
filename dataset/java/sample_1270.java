public class sample_1270 {
    public static void main(String[] args) {
        System.out.println(simulate());
    }

    public static int simulate() {
        int a = 1;
        int b = 1;
        while (true) {
            int temp = b;
            b = a + b;
            a = temp;
            if (a > 1000) {
                break;
            }
        }
        return a;
    }
}