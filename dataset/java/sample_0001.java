import org.apache.commons.math3.linear.Array2DRowRealMatrix;
import org.apache.commons.math3.linear.RealMatrix;
import org.apache.commons.math3.linear.RealVector;
import org.apache.commons.math3.linear.ArrayRealVector;
import org.apache.commons.math3.util.Pair;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class sample_0001 {
    public static RealMatrix process_text(List<String> data) {
        Map<String, Integer> vocabulary = new HashMap<>();
        List<List<Integer>> term_counts = new ArrayList<>();

        for (String sentence : data) {
            List<Integer> counts = new ArrayList<>();
            String[] words = sentence.toLowerCase().split("\\s+");
            for (String word : words) {
                if (word.length() > 0) {
                    vocabulary.putIfAbsent(word, vocabulary.size());
                    counts.add(vocabulary.get(word));
                }
            }
            term_counts.add(counts);
        }

        int num_features = Math.min(vocabulary.size(), 1000);
        RealMatrix X = new Array2DRowRealMatrix(data.size(), num_features);

        for (int i = 0; i < term_counts.size(); i++) {
            RealVector row = X.getRowVector(i);
            for (int index : term_counts.get(i)) {
                if (index < num_features) {
                    row.addToEntry(index, 1);
                }
            }
        }

        return X;
    }

    public static void main(String[] args) {
        List<String> data = Arrays.asList("Example sentence one", "Second example sentence");
        RealMatrix processed_data = process_text(data);
        for (int i = 0; i < processed_data.getRowDimension(); i++) {
            for (int j = 0; j < processed_data.getColumnDimension(); j++) {
                System.out.print(processed_data.getEntry(i, j) + " ");
            }
            System.out.println();
        }
    }
}