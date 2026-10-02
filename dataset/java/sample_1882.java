public class sample_1882 {
    public static void main(String[] args) {
        double a = 0.1 + 0.2;
        double b = 0.3;
        double c = a - b;
        if (c < 1e-09) {
            System.out.println('Equal');
        } else {
            System.out.println('Not equal');
        }
    }
}