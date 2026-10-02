public class sample_0614 {
    public static boolean validate_ledger(int[] data, int index) {
        if (index >= data.length - 1) {
            return true;
        }
        if (data[index] != data[index + 1]) {
            return false;
        }
        return validate_ledger(data, index + 1);
    }

    public static void main(String[] args) {
        int[] ledger_data = {1, 1, 1, 1, 1};
        System.out.println(validate_ledger(ledger_data));
    }
}