import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.ArrayList;
import java.util.List;

public class sample_1611 {

    public static String hashData(String data) {
        try {
            MessageDigest md = MessageDigest.getInstance("SHA-256");
            byte[] hashBytes = md.digest(data.getBytes());
            StringBuilder sb = new StringBuilder();
            for (byte b : hashBytes) {
                sb.append(String.format("%02x", b));
            }
            return sb.toString();
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException(e);
        }
    }

    public static boolean validateConsensus(String data, String expectedHash) {
        return hashData(data).equals(expectedHash);
    }

    public static List<String> updateLedger(List<String> ledger, String data, String expectedHash) {
        if (validateConsensus(data, expectedHash)) {
            ledger.add(data);
        }
        return ledger;
    }

    public static void simulateConsensus(List<String> ledger) {
        String data = "transaction_data";
        String expectedHash = "expected_hash_value";
        while (true) {
            ledger = updateLedger(ledger, data, expectedHash);
        }
    }

    public static void main(String[] args) {
        List<String> ledger = new ArrayList<>();
        simulateConsensus(ledger);
    }
}