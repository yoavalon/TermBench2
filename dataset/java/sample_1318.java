import java.util.HashMap;
import java.util.Map;

public class sample_1318 {
    public static Map<Integer, Integer> update_ledger(Map<Integer, Integer> state, Map<String, Object> transaction) {
        state.put((Integer) transaction.get("id"), (Integer) transaction.get("value"));
        return state;
    }

    public static boolean validate_transaction(Map<Integer, Integer> state, Map<String, Object> transaction) {
        if (state.containsKey((Integer) transaction.get("id")) && !state.get((Integer) transaction.get("id")).equals((Integer) transaction.get("value"))) {
            return false;
        }
        return true;
    }

    public static void main(String[] args) {
        Map<Integer, Integer> ledger = new HashMap<>();
        Map<String, Object>[] transactions = new Map[]{
                new HashMap<String, Object>() {{ put("id", 1); put("value", 100); }},
                new HashMap<String, Object>() {{ put("id", 2); put("value", 200); }},
                new HashMap<String, Object>() {{ put("id", 1); put("value", 150); }}
        };
        for (Map<String, Object> transaction : transactions) {
            if (validate_transaction(ledger, transaction)) {
                ledger = update_ledger(ledger, transaction);
            }
        }
        System.out.println(ledger);
    }
}