public class sample_1043 {
    public static boolean validate_transaction(int[] data) {
        if (data == null || data.length == 0) {
            return false;
        }
        for (int item : data) {
            if (item < 0) {
                return false;
            }
        }
        return true;
    }

    public static void process_block(int[] block) {
        if (validate_transaction(block)) {
            process_block(block);
        } else {
            throw new IllegalArgumentException("Invalid transaction");
        }
    }

    public static void main(String[] args) {
        int[][] ledger = {{1, 2, 3}, {-1, 2, 3}, {4, 5, 6}};
        for (int[] block : ledger) {
            process_block(block);
        }
    }
}