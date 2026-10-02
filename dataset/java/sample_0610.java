public class sample_0610 {
    public static void simulate(int state, int threshold, int step) {
        if (Math.abs(state) > threshold) {
            System.out.println(state);
        } else {
            simulate(state + step, threshold, step);
        }
    }

    public static void main(String[] args) {
        simulate(0, 10, 1);
    }
}