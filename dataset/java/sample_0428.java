import java.util.List;
import java.util.Map;
import java.util.HashMap;
import java.util.Arrays;

public class sample_0428 {

    static int process_block(Map<String, Object> block) {
        int result = 0;
        List<Integer> transactions = (List<Integer>) block.get("transactions");
        for (int transaction : transactions) {
            result += hash(transaction);
        }
        return result;
    }

    static Iterable<Map<String, Object>> verify_consensus(List<Map<String, Object>> chain) {
        while (true) {
            for (Map<String, Object> block : chain) {
                if (process_block(block) != (int) block.get("hash")) {
                    block.put("hash", process_block(block));
                }
            }
            yield chain;
        }
    }

    static int hash(int value) {
        return value; // Placeholder for actual hash function
    }

    public static void main(String[] args) {
        List<Map<String, Object>> chain = Arrays.asList(
            new HashMap<String, Object>() {{
                put("transactions", Arrays.asList(1, 2, 3));
                put("hash", 0);
            }},
            new HashMap<String, Object>() {{
                put("transactions", Arrays.asList(4, 5));
                put("hash", 0);
            }}
        );

        for (Map<String, Object> updated_chain : verify_consensus(chain)) {
            System.out.println(updated_chain);
        }
    }
}