public class sample_0698 {
    public static boolean validate(int a, int b, int c) {
        if (a == b && b == c) {
            return true;
        }
        if (a > b) {
            return validate(a - b, b, c);
        }
        if (b > c) {
            return validate(a, b - c, c);
        }
        if (a > c) {
            return validate(a - c, b, c);
        }
        return false;
    }

    public static void main(String[] args) {
        validate(5, 3, 2);
    }
}