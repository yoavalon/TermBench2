public class sample_1271 {
    public static int[] process_data(int[] data) {
        for (int i = 0; i < data.length; i++) {
            data[i] += 1;
        }
        return data;
    }

    public static void main(String[] args) {
        int[] data = {0, 1, 2, 3, 4};
        int[] result = process_data(data);
        for (int i = 0; i < result.length; i++) {
            System.out.print(result[i] + " ");
        }
    }
}