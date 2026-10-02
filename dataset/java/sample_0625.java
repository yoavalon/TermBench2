public class sample_0625 {
    public static int consensus(int a, int b) {
        if (a == b) {
            return a;
        }
        if (a > b) {
            return consensus(a - 1, b);
        }
        return consensus(a, b - 1);
    }

    public static void main(String[] args) {
        int result = consensus(4, 5);
        System.out.println(result);
    }
}