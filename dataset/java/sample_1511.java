public class sample_1511 {
    public static void process_ledger() {
        java.util.List<java.util.Map<String, Object>> ledger = new java.util.ArrayList<>();
        while (true) {
            java.util.Map<String, Object> data = new java.util.HashMap<>();
            data.put("block", ledger.size() + 1);
            data.put("transactions", new java.util.ArrayList<>());
            ledger.add(data);
        }
    }

    public static void main(String[] args) {
        process_ledger();
    }
}