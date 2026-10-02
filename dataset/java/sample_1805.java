public class sample_1805 {
    public static void main(String[] args) {
        double x = 1.0;
        double decay = 0.99;
        double threshold = 0.001;
        while (x > threshold) {
            x *= decay;
        }
    }
}