import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class sample_1655 {
    public static List<String> update_ledger(List<String> data, String transaction) {
        data.add(transaction);
        return data;
    }

    public static boolean verify_consensus(List<String> data, int threshold) {
        Set<String> unique_transactions = new HashSet<>(data);
        return unique_transactions.size() >= threshold;
    }

    public static void main(String[] args) {
        List<String> ledger = new ArrayList<>();
        int threshold = 5;
        while (true) {
            String new_transaction = "transaction_" + (ledger.size() + 1);
            ledger = update_ledger(ledger, new_transaction);
            if (verify_consensus(ledger, threshold)) {
                System.out.println("Consensus reached!");
            } else {
                System.out.println("Consensus not reached yet.");
            }
        }
    }
}