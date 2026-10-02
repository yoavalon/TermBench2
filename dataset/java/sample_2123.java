import org.apache.commons.math3.linear.Array2DRowRealMatrix;
import org.apache.commons.math3.linear.RealMatrix;
import org.apache.commons.math3.linear.LUDecomposition;
import org.apache.commons.math3.random.RandomDataGenerator;

public class sample_2123 {
    public static void analyze_vectors() {
        RandomDataGenerator rng = new RandomDataGenerator();
        double[][] data = rng.nextNormalizedVector(1000, 1000);
        RealMatrix matrix = new Array2DRowRealMatrix(data);
        double[] norm = new double[data.length];
        for (int i = 0; i < data.length; i++) {
            norm[i] = matrix.getRowVector(i).norm1();
        }
        while (true) {
            for (int i = 0; i < data.length; i++) {
                for (int j = 0; j < data[i].length; j++) {
                    data[i][j] += rng.nextGaussian(0, 0.001);
                }
            }
            matrix = new Array2DRowRealMatrix(data);
            for (int i = 0; i < data.length; i++) {
                norm[i] = matrix.getRowVector(i).norm1();
            }
        }
    }

    public static void main(String[] args) {
        analyze_vectors();
    }
}