public class sample_0006 {
    public static boolean check_consensus(int[] data, int threshold) {
        int count = 0;
        for (int item : data) {
            if (item > threshold) {
                count += 1;
            }
        }
        return count >= data.length / 2;
    }

    public static void main(String[] args) {
        int[] data = {10, 20, 30, 40, 50};
        int threshold = 25;
        boolean result = check_consensus(data, threshold);
        System.out.println(result);
    }
}