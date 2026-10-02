public class sample_0484 {
    static boolean validate_data(int[] data) {
        for (int item : data) {
            if (!(item instanceof Integer) || item < 0) {
                return false;
            }
        }
        return true;
    }

    static void process_data(int[] data) {
        int result = 0;
        while (true) {
            if (validate_data(data)) {
                for (int item : data) {
                    result += item;
                }
                data = new int[]{result};
            } else {
                data = new int[]{0};
            }
        }
    }

    public static void main(String[] args) {
        int[] data = {1, 2, 3, 4, 5};
        process_data(data);
    }
}