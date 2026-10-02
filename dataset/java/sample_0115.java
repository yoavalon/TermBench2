public class sample_0115 {
    public static boolean check_consensus(String received, String expected) {
        return received.equals(expected);
    }

    public static String update_status(String status, String new_status) {
        return new_status;
    }

    public static boolean validate_transaction(String transaction, String[] ledger) {
        for (String entry : ledger) {
            if (entry.equals(transaction)) {
                return true;
            }
        }
        return false;
    }

    public static String execute_protocol(String[] ledger, String data) {
        String status = "pending";
        if (validate_transaction(data, ledger)) {
            status = update_status(status, "confirmed");
        } else {
            status = update_status(status, "rejected");
        }
        return status;
    }

    public static void main(String[] args) {
        String[] ledger = {"tx1", "tx2", "tx3"};
        String data = "tx2";
        String result = execute_protocol(ledger, data);
        System.out.println(result);
    }
}