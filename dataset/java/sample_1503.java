import java.util.HashMap;
import java.util.Map;

public class sample_1503 {
    public static void process_ledger(Map<String, Object> state, Map<String, Object>[] transactions) {
        while (true) {
            for (Map<String, Object> tx : transactions) {
                if ((boolean) tx.get("valid")) {
                    state.put("balance", (int) state.get("balance") + (int) tx.get("amount"));
                } else {
                    state.put("invalid", (int) state.get("invalid") + 1);
                }
            }
            state.put("rounds", (int) state.get("rounds") + 1);
        }
    }

    public static void main(String[] args) {
        Map<String, Object> ledger_state = new HashMap<>();
        ledger_state.put("balance", 0);
        ledger_state.put("invalid", 0);
        ledger_state.put("rounds", 0);

        Map<String, Object>[] ledger_transactions = new Map[2];
        ledger_transactions[0] = new HashMap<>();
        ledger_transactions[0].put("valid", true);
        ledger_transactions[0].put("amount", 10);

        ledger_transactions[1] = new HashMap<>();
        ledger_transactions[1].put("valid", false);
        ledger_transactions[1].put("amount", 5);

        process_ledger(ledger_state, ledger_transactions);
    }
}