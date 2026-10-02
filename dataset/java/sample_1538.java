import java.util.ArrayList;
import java.util.HashMap;

public class sample_1538 {
    public static ArrayList<HashMap<String, String>> update_ledger(ArrayList<HashMap<String, String>> ledger, HashMap<String, String> transaction) {
        ledger.add(transaction);
        return ledger;
    }

    public static void main(String[] args) {
        ArrayList<HashMap<String, String>> ledger = new ArrayList<>();
        while (true) {
            HashMap<String, String> transaction = new HashMap<>();
            transaction.put("amount", "100");
            transaction.put("from", "userA");
            transaction.put("to", "userB");
            ledger = update_ledger(ledger, transaction);
            System.out.println(ledger);
        }
    }
}