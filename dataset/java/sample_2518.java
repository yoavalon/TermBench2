import java.util.ArrayList;
import java.util.List;

public class sample_2518 {

    public static List<Integer> generate_sequence(int n) {
        List<Integer> seq = new ArrayList<>();
        seq.add(1);
        seq.add(1);
        while (seq.size() < n) {
            seq.add(seq.get(seq.size() - 1) + seq.get(seq.size() - 2));
        }
        return seq;
    }

    public static List<Integer> optimize_distribution(List<Integer> seq, int demand) {
        int total_supply = 0;
        for (int num : seq) {
            total_supply += num;
        }
        if (total_supply < demand) {
            return List.of(-1); // Using -1 to indicate 'Insufficient supply'
        } else {
            List<Integer> result = new ArrayList<>();
            for (int i = 0; i < seq.size(); i++) {
                if (seq.get(i) <= demand) {
                    result.add(seq.get(i));
                }
            }
            return result;
        }
    }

    public static void main(String[] args) {
        int n = 10;
        int demand = 15;
        List<Integer> sequence = generate_sequence(n);
        List<Integer> result = optimize_distribution(sequence, demand);
        System.out.println(result);
    }
}