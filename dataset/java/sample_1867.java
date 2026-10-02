import org.apache.commons.lang3.ArrayUtils;
import org.apache.commons.math3.linear.RealMatrix;
import org.apache.commons.math3.linear.Array2DRowRealMatrix;
import org.apache.commons.math3.linear.SingularValueDecomposition;

import java.util.ArrayList;
import java.util.List;

public class sample_1867 {
    public static RealMatrix process_text(List<String> data) {
        TfidfVectorizer vectorizer = new TfidfVectorizer();
        RealMatrix matrix = vectorizer.fit_transform(data);
        return matrix;
    }

    public static void main(String[] args) {
        List<String> data = new ArrayList<>();
        data.add("hello world");
        data.add("data science");
        data.add("python programming");
        RealMatrix result = process_text(data);
        System.out.println(result);
    }
}

class TfidfVectorizer {
    public RealMatrix fit_transform(List<String> data) {
        // Placeholder for the actual implementation of TfidfVectorizer
        // This is a simplified version for demonstration purposes
        double[][] tfidfMatrix = new double[data.size()][data.size()];
        for (int i = 0; i < data.size(); i++) {
            for (int j = 0; j < data.size(); j++) {
                tfidfMatrix[i][j] = 1.0; // Dummy values
            }
        }
        return new Array2DRowRealMatrix(tfidfMatrix);
    }
}