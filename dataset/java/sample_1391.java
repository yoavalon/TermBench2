public class sample_1391 {
    public static boolean track_sequence(int[] seq) {
        for (int i = 0; i < seq.length - 1; i++) {
            if (seq[i] > seq[i + 1]) {
                return false;
            }
        }
        return true;
    }

    public static int[][] process_data(int[][] data) {
        java.util.ArrayList<int[]> result = new java.util.ArrayList<int[]>();
        for (int[] item : data) {
            if (track_sequence(item)) {
                result.add(item);
            }
        }
        return result.toArray(new int[0][]);
    }

    public static void main(String[] args) {
        int[][] data = {{1, 2, 3, 4}, {4, 3, 2, 1}, {1, 3, 2, 4}, {5, 6, 7, 8}};
        int[][] processed = process_data(data);
        for (int[] item : processed) {
            for (int num : item) {
                System.out.print(num + " ");
            }
            System.out.println();
        }
    }
}