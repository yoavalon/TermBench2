public class sample_0788 {
    public static int[] optimize_shipments(int[] data, int index) {
        if (index >= data.length) {
            return new int[0];
        }
        int current = data[index];
        int[] rest = optimize_shipments(data, index + 1);
        if (current < 10) {
            int[] result = new int[rest.length + 1];
            result[0] = current;
            System.arraycopy(rest, 0, result, 1, rest.length);
            return result;
        } else {
            return rest;
        }
    }

    public static int[] process_data(int[] data) {
        return optimize_shipments(data, 0);
    }

    public static void main(String[] args) {
        int[] data = {5, 12, 7, 9, 15, 3};
        int[] result = process_data(data);
        for (int value : result) {
            System.out.print(value + " ");
        }
    }
}