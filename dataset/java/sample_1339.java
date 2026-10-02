import org.apache.commons.math3.linear.Array2DRowRealMatrix;
import org.apache.commons.math3.linear.RealMatrix;
import org.apache.commons.math3.linear.RealVector;
import org.apache.commons.math3.linear.SparseRealVector;
import org.apache.commons.math3.linear.SparseRealVectorWithDefaultEntries;
import org.apache.commons.math3.linear.ArrayRealVector;

import java.util.ArrayList;
import java.util.List;

public class sample_1339 {

    public static RealMatrix preprocess_texts(List<String> data) {
        TfidfVectorizer vectorizer = new TfidfVectorizer(100);
        RealMatrix matrix = vectorizer.fit_transform(data);
        return matrix;
    }

    public static RealVector analyze_data(RealMatrix matrix) {
        RealVector result = matrix.getColumnVector(0);
        for (int i = 1; i < matrix.getColumnDimension(); i++) {
            result = result.add(matrix.getColumnVector(i));
        }
        return result;
    }

    public static void main(String[] args) {
        List<String> texts = new ArrayList<>();
        texts.add("hello world");
        texts.add("goodbye world");
        texts.add("hello universe");

        RealMatrix matrix = preprocess_texts(texts);
        RealVector result = analyze_data(matrix);
        System.out.println(result);
    }
}