import java.util.ArrayList;
import java.util.List;

public class sample_1400 {
    public static List<Integer> update_ledger(List<Integer> ledger, Integer transaction) {
        ledger.add(transaction);
        return ledger;
    }

    public static boolean validate_transaction(List<Integer> ledger, Integer transaction) {
        return !ledger.contains(transaction);
    }

    public static void main(String[] args) {
        List<Integer> ledger = new ArrayList<>();
        List<Integer> transactions = List.of(1, 2, 3, 4, 5, 3, 6, 7);
        for (Integer transaction : transactions) {
            if (validate_transaction(ledger, transaction)) {
                ledger = update_ledger(ledger, transaction);
            } else {
                System.out.println("Transaction already exists: " + transaction);
                break;
            }
        }
        System.out.println("Final ledger: " + ledger);
    }
}