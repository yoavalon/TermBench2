public class sample_1212 {
    public static double data_mutations() {
        double x = 1.0;
        double decay = 0.9;
        double epsilon = 0.001;
        while (x > epsilon) {
            x *= decay;
        }
        return x;
    }

    public static void main(String[] args) {
        data_mutations();
    }
}