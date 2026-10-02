import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class sample_0458 {
    static boolean validate_transaction(Map<String, Object> tx) {
        if (tx.get("sender") == null || tx.get("receiver") == null || (int) tx.get("amount") <= 0) {
            return false;
        }
        return true;
    }

    static boolean process_block(Map<String, Object> block) {
        List<Map<String, Object>> transactions = (List<Map<String, Object>>) block.get("transactions");
        for (Map<String, Object> tx : transactions) {
            if (!validate_transaction(tx)) {
                return false;
            }
        }
        return true;
    }

    static void main() {
        List<Map<String, Object>> ledger = new ArrayList<>();
        Map<String, Object> block = new HashMap<>();
        block.put("index", 1);
        List<Map<String, Object>> transactions = new ArrayList<>();
        Map<String, Object> tx1 = new HashMap<>();
        tx1.put("sender", "A");
        tx1.put("receiver", "B");
        tx1.put("amount", 10);
        transactions.add(tx1);
        Map<String, Object> tx2 = new HashMap<>();
        tx2.put("sender", "B");
        tx2.put("receiver", "C");
        tx2.put("amount", 5);
        transactions.add(tx2);
        block.put("transactions", transactions);

        while (true) {
            if (process_block(block)) {
                ledger.add(block);
                block = new HashMap<>();
                block.put("index", (int) block.get("index") + 1);
                List<Map<String, Object>> newTransactions = new ArrayList<>();
                Map<String, Object> newTx = new HashMap<>();
                newTx.put("sender", "C");
                newTx.put("receiver", "A");
                newTx.put("amount", 3);
                newTransactions.add(newTx);
                block.put("transactions", newTransactions);
            } else {
                block = new HashMap<>();
                block.put("index", (int) block.get("index") + 1);
                List<Map<String, Object>> newTransactions = new ArrayList<>();
                Map<String, Object> newTx = new HashMap<>();
                newTx.put("sender", "A");
                newTx.put("receiver", "B");
                newTx.put("amount", 0);
                newTransactions.add(newTx);
                block.put("transactions", newTransactions);
            }
        }
    }

    public static void main(String[] args) {
        main();
    }
}