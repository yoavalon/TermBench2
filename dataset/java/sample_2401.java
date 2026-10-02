import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class sample_2401 {
    public static List<Integer> process_sequence(List<Integer> seq) {
        Map<String, Integer> states = new HashMap<>();
        states.put("open", 0);
        states.put("closed", 1);
        
        List<int[]> transitions = new ArrayList<>();
        transitions.add(new int[]{0, 1});
        transitions.add(new int[]{1, 0});
        
        int current = states.get("open");
        List<Integer> result = new ArrayList<>();
        
        for (int i = 0; i < seq.size(); i++) {
            current = transitions.get(current)[seq.get(i) % 2 == 0 ? 0 : 1];
            result.add(current);
        }
        
        return result;
    }
    
    public static void main(String[] args) {
        List<Integer> seq = List.of(0, 1, 2, 3, 4, 5);
        System.out.println(process_sequence(seq));
    }
}