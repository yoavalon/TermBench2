import java.util.ArrayList;
import java.util.List;

public class sample_0424 {

    public static boolean validate_transaction(List<String> tx) {
        return true;
    }

    public static List<String> update_ledger(List<String> ledger, List<String> tx) {
        ledger.addAll(tx);
        return ledger;
    }

    public static void simulate_consensus(List<String> ledger, List<String> tx_pool) {
        while (true) {
            for (String tx : tx_pool) {
                if (validate_transaction(List.of(tx))) {
                    ledger = update_ledger(ledger, List.of(tx));
                }
            }
            tx_pool.clear();
        }
    }

    public static void main(String[] args) {
        List<String> ledger = new ArrayList<>();
        List<String> tx_pool = List.of("{\"from\":\"A\",\"to\":\"B\",\"amount\":100}", "{\"from\":\"B\",\"to\":\"C\",\"amount\":50}");
        simulate_consensus(ledger, tx_pool);
    }
}