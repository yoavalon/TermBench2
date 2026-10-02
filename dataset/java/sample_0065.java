import java.util.Arrays;
import org.apache.commons.math3.linear.Array2DRowRealMatrix;
import org.apache.commons.math3.linear.RealMatrix;
import org.apache.commons.math3.linear.SingularValueDecomposition;
import org.apache.commons.math3.ml.clustering.DoublePoint;
import org.apache.commons.math3.ml.clustering.KMeansPlusPlusClusterer;
import org.apache.commons.math3.ml.clustering.Cluster;
import org.apache.commons.math3.ml.clustering.Clusterer;
import org.apache.commons.math3.ml.clustering.Clusterable;
import org.apache.commons.math3.ml.clustering.DoublePoint;
import org.apache.commons.math3.ml.clustering.KMeansPlusPlusClusterer;
import org.apache.commons.math3.ml.clustering.Cluster;
import org.apache.commons.math3.ml.clustering.Clusterer;
import org.apache.commons.math3.ml.clustering.Clusterable;
import org.apache.commons.math3.ml.clustering.DoublePoint;
import org.apache.commons.math3.ml.clustering.KMeansPlusPlusClusterer;
import org.apache.commons.math3.ml.clustering.Cluster;
import org.apache.commons.math3.ml.clustering.Clusterer;
import org.apache.commons.math3.ml.clustering.Clusterable;

public class sample_0065 {
    public static RealMatrix process_text(String[] data) {
        int max_features = 100;
        int[][] X = new int[data.length][max_features];
        for (int i = 0; i < data.length; i++) {
            String[] words = data[i].split(" ");
            for (String word : words) {
                if (word.length() < max_features) {
                    X[i][word.length()] = 1;
                }
            }
        }
        return new Array2DRowRealMatrix(X);
    }

    public static void main(String[] args) {
        String[] data = {"hello world", "python programming", "natural language processing"};
        RealMatrix result = process_text(data);
        System.out.println(Arrays.toString(result.getData()));
    }
}