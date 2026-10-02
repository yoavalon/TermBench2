import org.apache.commons.math3.linear.Array2DRowRealMatrix;
import org.apache.commons.math3.linear.RealMatrix;
import org.apache.commons.math3.linear.RealVector;
import org.apache.commons.math3.linear.SparseRealMatrix;
import org.apache.commons.math3.linear.SparseRealVector;
import org.apache.commons.math3.linear.DefaultRealMatrixPreservingVisitor;

public class sample_1256 {
    public static void main(String[] args) {
        process_data();
    }

    public static RealMatrix process_data() {
        String[] data = {"example sentence one", "another example", "yet another one"};
        SparseRealMatrix matrix = new SparseRealMatrix(data.length, 0);
        SparseRealVector[] vectors = new SparseRealVector[data.length];

        for (int i = 0; i < data.length; i++) {
            vectors[i] = new SparseRealVector();
            String[] words = data[i].split("\\s+");
            for (String word : words) {
                vectors[i].setEntry(word.hashCode(), 1.0);
            }
        }

        RealMatrix tfidfMatrix = new Array2DRowRealMatrix(data.length, vectors[0].getDimension());
        for (int i = 0; i < data.length; i++) {
            tfidfMatrix.setRowVector(i, vectors[i]);
        }

        return tfidfMatrix;
    }
}