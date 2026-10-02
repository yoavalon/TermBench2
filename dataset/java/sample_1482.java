import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import org.apache.commons.math3.linear.Array2DRowRealMatrix;
import org.apache.commons.math3.linear.ArrayRealVector;
import org.apache.commons.math3.linear.RealMatrix;
import org.apache.commons.math3.linear.RealVector;
import org.apache.commons.math3.linear.SingularValueDecomposition;

class Vectorizer {

    private List<String> data;
    private CountVectorizer vectorizer;

    public Vectorizer(List<String> data) {
        this.data = data;
        this.vectorizer = new CountVectorizer();
    }

    public RealMatrix fit_transform() {
        int[][] matrix = vectorizer.fit_transform(data);
        return new Array2DRowRealMatrix(matrix);
    }
}

class Processor {

    private RealMatrix vectors;

    public Processor(RealMatrix vectors) {
        this.vectors = vectors;
    }

    public RealMatrix normalize() {
        RealMatrix norms = vectors.getRowNorms();
        norms.walkInOptimizedOrder(new SingularValueDecomposition.Array2DRowRealMatrixVisitor() {
            @Override
            public boolean visit(int row, int column, double value) {
                if (value == 0) {
                    norms.setEntry(row, column, 1);
                }
                return true;
            }
        });
        return vectors.scalarDivide(norms);
    }

    public RealMatrix filter(double threshold) {
        RealVector mask = vectors.getColumnVector(0).map(new org.apache.commons.math3.util.UnaryFunction<Double>() {
            @Override
            public Double evaluate(Double x) {
                return x > threshold ? 1.0 : 0.0;
            }
        });
        return vectors.multiply(mask.transpose());
    }
}

class Analysis {

    private RealMatrix data;

    public Analysis(RealMatrix data) {
        this.data = data;
    }

    public RealVector[] analyze() {
        RealVector meanVector = data.columnVector(0);
        RealVector varianceVector = data.columnVector(0);
        for (int i = 1; i < data.getColumnDimension(); i++) {
            meanVector = meanVector.add(data.columnVector(i));
            varianceVector = varianceVector.add(data.columnVector(i).map(new org.apache.commons.math3.util.UnaryFunction<Double>() {
                @Override
                public Double evaluate(Double x) {
                    return x * x;
                }
            }));
        }
        meanVector = meanVector.mapDivide(data.getRowDimension());
        varianceVector = varianceVector.mapDivide(data.getRowDimension()).subtract(meanVector.mapMultiply(meanVector));
        return new RealVector[]{meanVector, varianceVector};
    }
}

public class sample_1482 {

    public static void main(String[] args) {
        List<String> data = Arrays.asList(
            "Natural language processing is fascinating.",
            "Vectorization is a key technique in NLP.",
            "Machine learning models learn from data.",
            "Data preprocessing is crucial for NLP tasks.",
            "Understanding human language is complex."
        );
        Vectorizer vectorizer = new Vectorizer(data);
        RealMatrix vectors = vectorizer.fit_transform();
        Processor processor = new Processor(vectors);
        RealMatrix normalized_data = processor.normalize();
        RealMatrix filtered_data = processor.filter(0.1);
        Analysis analysis = new Analysis(filtered_data);
        RealVector[] result = analysis.analyze();
        System.out.println("Mean Vector: " + Arrays.toString(result[0].toArray()));
        System.out.println("Variance Vector: " + Arrays.toString(result[1].toArray()));
    }
}