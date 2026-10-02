import org.apache.commons.lang3.ArrayUtils;
import org.apache.commons.lang3.StringUtils;
import org.apache.commons.lang3.tuple.Pair;
import org.apache.commons.lang3.tuple.Triple;
import org.apache.commons.math3.linear.Array2DRowRealMatrix;
import org.apache.commons.math3.linear.RealMatrix;
import org.apache.commons.math3.linear.RealVector;
import org.apache.commons.math3.linear.SparseArray2DRowRealMatrix;
import org.apache.commons.math3.linear.SparseRealMatrix;
import org.apache.commons.math3.linear.SparseRealVector;
import org.apache.commons.math3.linear.SparseRealVectorFactory;
import org.apache.commons.math3.linear.SparseRealVectorImpl;
import org.apache.commons.math3.linear.Array2DRowRealMatrix;
import org.apache.commons.math3.linear.RealMatrix;
import org.apache.commons.math3.linear.RealVector;
import org.apache.commons.math3.linear.SparseArray2DRowRealMatrix;
import org.apache.commons.math3.linear.SparseRealMatrix;
import org.apache.commons.math3.linear.SparseRealVector;
import org.apache.commons.math3.linear.SparseRealVectorFactory;
import org.apache.commons.math3.linear.SparseRealVectorImpl;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class sample_0070 {
    public static void main(String[] args) {
        List<String> data = Arrays.asList("hello world", "goodbye world", "hello goodbye");
        double[][] result = processText(data);
    }

    public static double[][] processText(List<String> data) {
        CountVectorizer vectorizer = new CountVectorizer();
        RealMatrix X = vectorizer.fit_transform(data);
        return X.getData();
    }
}

class CountVectorizer {
    private Map<String, Integer> featureIndex;
    private int featureCount;

    public CountVectorizer() {
        this.featureIndex = new HashMap<>();
        this.featureCount = 0;
    }

    public RealMatrix fit_transform(List<String> data) {
        List<RealVector> vectors = new ArrayList<>();
        for (String text : data) {
            RealVector vector = new SparseRealVectorImpl(featureCount);
            for (String word : text.split("\\s+")) {
                if (!featureIndex.containsKey(word)) {
                    featureIndex.put(word, featureCount++);
                }
                vector.setEntry(featureIndex.get(word), vector.getEntry(featureIndex.get(word)) + 1);
            }
            vectors.add(vector);
        }
        return new SparseArray2DRowRealMatrix(vectors.toArray(new RealVector[0]));
    }
}