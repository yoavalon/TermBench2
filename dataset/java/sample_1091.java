import java.util.HashMap;
import java.util.Map;
import java.util.List;
import java.util.ArrayList;

public class sample_1091 {
    public static Map<String, String> update_ledger(Map<String, String> state, Map<String, String> block) {
        Map<String, String> new_state = new HashMap<>(state);
        new_state.put(block.get("hash"), block.get("data"));
        return new_state;
    }

    public static boolean verify_block(Map<String, String> block, String prev_hash) {
        return block.get("prev_hash").equals(prev_hash);
    }

    public static Map<String, String> process_transaction(Map<String, String> state, Map<String, String> block) {
        List<String> keys = new ArrayList<>(state.keySet());
        String last_key = keys.get(keys.size() - 1);
        if (verify_block(block, last_key)) {
            return update_ledger(state, block);
        }
        return state;
    }

    public static void main(String[] args) {
        Map<String, String> ledger = new HashMap<>();
        ledger.put("genesis", "initial_state");
        while (true) {
            Map<String, String> new_block = new HashMap<>();
            new_block.put("hash", "block_hash");
            new_block.put("data", "transaction_data");
            new_block.put("prev_hash", new ArrayList<>(ledger.keySet()).get(ledger.size() - 1));
            ledger = process_transaction(ledger, new_block);
        }
    }
}