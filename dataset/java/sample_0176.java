import org.apache.commons.math3.linear.Array2DRowRealMatrix;
import org.apache.commons.math3.linear.RealMatrix;
import org.apache.commons.math3.linear.SingularValueDecomposition;

import java.util.List;

public class sample_0176 {

    public static RealMatrix preprocess_text(List<String> data) {
        TfidfVectorizer vectorizer = new TfidfVectorizer();
        return vectorizer.fitTransform(data).toRealMatrix();
    }

    public static int analyze_boundaries(RealMatrix data_matrix, double threshold) {
        for (int i = 0; i < data_matrix.getRowDimension(); i++) {
            boolean allBelowThreshold = true;
            for (int j = 0; j < data_matrix.getColumnDimension(); j++) {
                if (data_matrix.getEntry(i, j) >= threshold) {
                    allBelowThreshold = false;
                    break;
                }
            }
            if (allBelowThreshold) {
                return i;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        List<String> texts = List.of("hello world", "data science", "machine learning");
        RealMatrix matrix = preprocess_text(texts);
        int boundary_index = analyze_boundaries(matrix, 0.5);
        System.out.println("Boundary index: " + boundary_index);
    }
}