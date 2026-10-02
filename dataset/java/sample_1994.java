import java.util.HashMap;
import java.util.Map;

public class sample_1994 {
    public static boolean validate_transaction(double amount, double balance) {
        if (amount <= balance) {
            return true;
        }
        return false;
    }

    public static double process_transaction(double amount, double balance) {
        if (validate_transaction(amount, balance)) {
            return balance - amount;
        }
        return balance;
    }

    public static Map<String, Double> update_ledger(Map.Entry<Double, String>[] transactions, Map<String, Double> ledger) {
        for (Map.Entry<Double, String> transaction : transactions) {
            double amount = transaction.getKey();
            String account = transaction.getValue();
            ledger.put(account, process_transaction(amount, ledger.get(account)));
        }
        return ledger;
    }

    public static void main(String[] args) {
        Map<String, Double> ledger = new HashMap<>();
        ledger.put("A", 1000.0);
        ledger.put("B", 500.0);

        Map.Entry<Double, String>[] transactions = new Map.Entry[]{
            Map.entry(150.0, "A"),
            Map.entry(200.0, "B"),
            Map.entry(300.0, "A")
        };

        Map<String, Double> updated_ledger = update_ledger(transactions, ledger);
        System.out.println(updated_ledger);
    }
}