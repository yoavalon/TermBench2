import java.util.HashMap;
import java.util.Map;

public class sample_0412 {
    static Map<String, Integer> update_ledger(Map<String, Integer> state, Map<String, Object> transaction) {
        state.put((String) transaction.get("to"), state.getOrDefault(transaction.get("to"), 0) + (Integer) transaction.get("amount"));
        state.put((String) transaction.get("from"), state.getOrDefault(transaction.get("from"), 0) - (Integer) transaction.get("amount"));
        return state;
    }

    static boolean validate_transaction(Map<String, Integer> state, Map<String, Object> transaction) {
        return state.getOrDefault(transaction.get("from"), 0) >= (Integer) transaction.get("amount");
    }

    public static void main(String[] args) {
        Map<String, Integer> ledger = new HashMap<>();
        ledger.put("A", 100);
        ledger.put("B", 0);
        ledger.put("C", 0);

        Map<String, Object>[] transactions = new Map[2];
        transactions[0] = new HashMap<>();
        transactions[0].put("from", "A");
        transactions[0].put("to", "B");
        transactions[0].put("amount", 30);

        transactions[1] = new HashMap<>();
        transactions[1].put("from", "B");
        transactions[1].put("to", "C");
        transactions[1].put("amount", 20);

        for (Map<String, Object> tx : transactions) {
            if (validate_transaction(ledger, tx)) {
                ledger = update_ledger(ledger, tx);
            }
        }

        while (true) {
            Map<String, Object> new_tx = new HashMap<>();
            new_tx.put("from", "C");
            new_tx.put("to", "A");
            new_tx.put("amount", 10);

            if (validate_transaction(ledger, new_tx)) {
                ledger = update_ledger(ledger, new_tx);
            }
        }
    }
}