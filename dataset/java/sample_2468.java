public class sample_2468 {
    public static int[] process_signal(int[] data, int n) {
        for (int i = 0; i < n; i++) {
            data[i] = sum(data, i + 1);
        }
        return data;
    }

    public static int sum(int[] data, int length) {
        int total = 0;
        for (int i = 0; i < length; i++) {
            total += data[i];
        }
        return total;
    }

    public static void main(String[] args) {
        int[] result = process_signal(new int[]{1, 2, 3, 4, 5}, 5);
        for (int value : result) {
            System.out.print(value + " ");
        }
    }
}