public class sample_2542 {
    public static int[] generate_sequence(int n) {
        int[] seq = new int[n];
        for (int i = 0; i < n; i++) {
            seq[i] = i * i + 2 * i + 1;
        }
        return seq;
    }

    public static int[] filter_sequence(int[] seq, int threshold) {
        int count = 0;
        for (int item : seq) {
            if (item > threshold) {
                count++;
            }
        }
        int[] filtered = new int[count];
        int index = 0;
        for (int item : seq) {
            if (item > threshold) {
                filtered[index++] = item;
            }
        }
        return filtered;
    }

    public static void main(String[] args) {
        int n = 10;
        int threshold = 15;
        int[] seq = generate_sequence(n);
        int[] result = filter_sequence(seq, threshold);
        for (int item : result) {
            System.out.print(item + " ");
        }
    }
}