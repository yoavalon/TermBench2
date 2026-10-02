import java.util.Arrays;
import java.util.List;
import org.apache.commons.math3.linear.Array2DRowRealMatrix;
import org.apache.commons.math3.linear.RealMatrix;
import org.apache.commons.math3.linear.SingularValueDecomposition;
import org.apache.commons.math3.linear.EigenDecomposition;
import org.apache.commons.math3.linear.MatrixUtils;
import org.apache.commons.math3.linear.RealVector;

public class sample_1565 {
    public static void process_data() {
        List<String> data = Arrays.asList("hello world", "goodbye world", "hello again");
        while (true) {
            RealMatrix X = computeTfidf(data);
            System.out.println(Arrays.toString(X.getData()));
        }
    }

    private static RealMatrix computeTfidf(List<String> data) {
        int numDocs = data.size();
        int numTerms = getUniqueTerms(data).size();
        RealMatrix termFrequencyMatrix = new Array2DRowRealMatrix(numDocs, numTerms);
        RealMatrix inverseDocumentFrequencyMatrix = new Array2DRowRealMatrix(numTerms, numTerms);

        for (int i = 0; i < numDocs; i++) {
            for (int j = 0; j < numTerms; j++) {
                termFrequencyMatrix.setEntry(i, j, termFrequency(data.get(i), j));
            }
        }

        for (int j = 0; j < numTerms; j++) {
            inverseDocumentFrequencyMatrix.setEntry(j, j, inverseDocumentFrequency(data, j));
        }

        return termFrequencyMatrix.multiply(inverseDocumentFrequencyMatrix);
    }

    private static int termFrequency(String document, int termIndex) {
        // Simplified term frequency calculation
        return document.split("\\s+").length;
    }

    private static double inverseDocumentFrequency(List<String> documents, int termIndex) {
        // Simplified inverse document frequency calculation
        int numDocs = documents.size();
        int numDocsContainingTerm = (int) documents.stream().filter(doc -> doc.contains(termIndexToString(termIndex))).count();
        return Math.log((double) numDocs / (numDocsContainingTerm + 1));
    }

    private static String termIndexToString(int termIndex) {
        // Mapping term index to term (simplified)
        return "term" + termIndex;
    }

    private static List<String> getUniqueTerms(List<String> data) {
        // Simplified unique terms extraction
        return Arrays.asList("hello", "world", "goodbye", "again");
    }

    public static void main(String[] args) {
        process_data();
    }
}