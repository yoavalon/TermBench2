import java.util.Arrays;
import org.apache.commons.lang3.StringUtils;
import org.apache.commons.math3.linear.Array2DRowRealMatrix;
import org.apache.commons.math3.linear.RealMatrix;

public class sample_1250 {
    public static RealMatrix process_text(String[] data) {
        int maxWords = 0;
        for (String text : data) {
            maxWords = Math.max(maxWords, StringUtils.split(text, " ").length);
        }
        
        int[][] vectors = new int[data.length][maxWords];
        for (int i = 0; i < data.length; i++) {
            String[] words = StringUtils.split(data[i], " ");
            for (String word : words) {
                for (int j = 0; j < maxWords; j++) {
                    if (words[j].equals(word)) {
                        vectors[i][j]++;
                    }
                }
            }
        }
        
        return new Array2DRowRealMatrix(vectors);
    }

    public static void main(String[] args) {
        String[] sample_data = {"hello world", "data processing", "natural language"};
        RealMatrix result = process_text(sample_data);
        System.out.println(Arrays.deepToString(result.getData()));
    }
}