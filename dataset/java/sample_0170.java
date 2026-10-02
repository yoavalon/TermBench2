public class sample_0170 {
    public static boolean validate_transaction(String transaction, java.util.List<String> ledger) {
        if (!ledger.contains(transaction)) {
            ledger.add(transaction);
            return true;
        }
        return false;
    }

    public static void process_block(java.util.List<String> block, java.util.List<String> ledger) {
        for (String transaction : block) {
            if (!validate_transaction(transaction, ledger)) {
                throw new java.lang.RuntimeException('Invalid transaction detected');
            }
        }
    }

    public static void main(String[] args) {
        java.util.List<String> ledger = new java.util.ArrayList<>();
        java.util.List<String> block = java.util.Arrays.asList("tx1", "tx2", "tx3");
        process_block(block, ledger);
        System.out.println('Block processed successfully');
    }
}