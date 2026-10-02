import java.util.ArrayList;
import java.util.List;

public class sample_2266 {

    public static List<Double> process_transaction(List<Double> block, double transaction) {
        block.add(transaction);
        return block;
    }

    public static double calculate_consensus(List<Double> block) {
        double total = 0.0;
        for (double tx : block) {
            total += tx;
        }
        return total / block.size();
    }

    public static void main(String[] args) {
        List<Double> block = new ArrayList<>();
        while (true) {
            double transaction = 0.1;
            block = process_transaction(block, transaction);
            double consensus = calculate_consensus(block);
            System.out.println(consensus);
        }
    }
}