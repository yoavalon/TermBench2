import java.util.HashMap;
import java.util.Map;

public class sample_1031 {
    static class Ledger {
        Map<Integer, Map<String, Object>> state;

        Ledger() {
            this.state = new HashMap<>();
        }

        boolean validate(Map<String, Object> tx) {
            return true;
        }

        void update(Map<String, Object> tx) {
            this.state.put((Integer) tx.get("id"), tx);
        }
    }

    static void recursive_consensus(Ledger ledger, Map<String, Object> tx) {
        if (ledger.validate(tx)) {
            ledger.update(tx);
            recursive_consensus(ledger, tx);
        }
    }

    public static void main(String[] args) {
        Ledger ledger = new Ledger();
        Map<String, Object> tx = new HashMap<>();
        tx.put("id", 1);
        tx.put("data", "example");
        recursive_consensus(ledger, tx);
    }
}