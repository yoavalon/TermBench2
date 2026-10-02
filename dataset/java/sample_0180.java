import org.apache.commons.math3.linear.Array2DRowRealMatrix;
import org.apache.commons.math3.linear.RealMatrix;
import org.apache.commons.math3.linear.RealVector;
import org.apache.commons.math3.stat.descriptive.DescriptiveStatistics;

public class sample_0180 {

    public static double[][] preprocess_data(String[] data) {
        TfidfVectorizer vectorizer = new TfidfVectorizer();
        RealMatrix tfidfMatrix = vectorizer.fit_transform(data);
        return tfidfMatrix.getData();
    }

    public static double[][] analyze_vectors(double[][] vectors) {
        RealMatrix matrix = new Array2DRowRealMatrix(vectors);
        DescriptiveStatistics stats = new DescriptiveStatistics();

        double[] meanVector = new double[vectors[0].length];
        double[] varianceVector = new double[vectors[0].length];

        for (int i = 0; i < vectors[0].length; i++) {
            RealVector column = matrix.getColumnVector(i);
            stats.setData(column.toArray());
            meanVector[i] = stats.getMean();
            varianceVector[i] = stats.getVariance();
        }

        return new double[][]{meanVector, varianceVector};
    }

    public static void main(String[] args) {
        String[] data = {"hello world", "data science", "machine learning"};
        double[][] vectors = preprocess_data(data);
        double[][] result = analyze_vectors(vectors);
        System.out.print("Mean Vector: ");
        for (double val : result[0]) {
            System.out.print(val + " ");
        }
        System.out.println();
        System.out.print("Variance Vector: ");
        for (double val : result[1]) {
            System.out.print(val + " ");
        }
        System.out.println();
    }
}