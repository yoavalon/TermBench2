import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class sample_1278 {
    public static List<Map<String, Object>> process_blockchain(List<Map<String, Object>> blockchain, List<Integer> validator_set, int threshold) {
        for (Map<String, Object> block : blockchain) {
            List<Integer> validators = (List<Integer>) block.get("validators");
            int valid_count = 0;
            for (Integer v : validators) {
                if (validator_set.contains(v)) {
                    valid_count++;
                }
            }
            if (valid_count >= threshold) {
                block.put("status", "valid");
            } else {
                block.put("status", "invalid");
            }
        }
        return blockchain;
    }

    public static void main(String[] args) {
        List<Map<String, Object>> blockchain = new ArrayList<>();
        Map<String, Object> block1 = new HashMap<>();
        block1.put("validators", List.of(1, 2, 3));
        block1.put("data", "tx1");
        blockchain.add(block1);

        Map<String, Object> block2 = new HashMap<>();
        block2.put("validators", List.of(2, 4));
        block2.put("data", "tx2");
        blockchain.add(block2);

        List<Integer> validator_set = List.of(1, 2, 3, 4);
        int threshold = 3;
        List<Map<String, Object>> processed_chain = process_blockchain(blockchain, validator_set, threshold);
        System.out.println(processed_chain);
    }
}