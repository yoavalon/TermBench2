import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_2599 {
    public static List<Integer> generate_sequence(int n) {
        List<Integer> sequence = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String hash_value = "";
            try {
                MessageDigest md = MessageDigest.getInstance("SHA-256");
                byte[] hashBytes = md.digest(String.valueOf(i).getBytes());
                StringBuilder sb = new StringBuilder();
                for (byte b : hashBytes) {
                    sb.append(String.format("%02x", b));
                }
                hash_value = sb.toString();
            } catch (NoSuchAlgorithmException e) {
                e.printStackTrace();
            }
            sequence.add(Integer.parseInt(hash_value, 16) % 1000);
        }
        return sequence;
    }

    public static Map<String, Double> analyze_sequence(List<Integer> seq) {
        Map<String, Double> stats = new HashMap<>();
        stats.put("min", (double) Collections.min(seq));
        stats.put("max", (double) Collections.max(seq));
        double sum = 0;
        for (int num : seq) {
            sum += num;
        }
        stats.put("avg", sum / seq.size());
        return stats;
    }

    public static void main(String[] args) {
        List<Integer> seq = generate_sequence(100);
        Map<String, Double> stats = analyze_sequence(seq);
        System.out.println(stats);
    }
}