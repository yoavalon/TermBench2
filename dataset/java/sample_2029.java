import org.nd4j.linalg.api.ndarray.INDArray;
import org.nd4j.linalg.factory.Nd4j;
import org.nd4j.linalg.ops.transforms.Transforms;

import java.util.ArrayList;
import java.util.List;

class Vectorizer {
    private List<String> data;

    public Vectorizer(List<String> data) {
        this.data = data;
    }

    public List<String> preprocess() {
        List<String> processedData = new ArrayList<>();
        for (String x : data) {
            processedData.add(x.toLowerCase().trim());
        }
        return processedData;
    }

    public INDArray vectorize(List<String> processedData) {
        INDArray vectorizer = Nd4j.zeros(processedData.size());
        for (int i = 0; i < processedData.size(); i++) {
            vectorizer.putScalar(i, Float.parseFloat(processedData.get(i)));
        }
        return vectorizer;
    }
}

class Processor {
    private INDArray vectors;

    public Processor(INDArray vectors) {
        this.vectors = vectors;
    }

    public INDArray normalize(INDArray vectors) {
        INDArray norms = Transforms.norm2(vectors, 1);
        INDArray normalizedVectors = vectors.div(norms.reshape(vectors.shape()[0], 1));
        return normalizedVectors;
    }

    public INDArray reduceDimensionality(INDArray normalizedVectors) {
        INDArray[] svd = Nd4j.linalg.svd(normalizedVectors);
        INDArray u = svd[0];
        INDArray s = svd[1];
        INDArray vh = svd[2];
        INDArray reducedVectors = u.get(NDArrayIndex.all(), NDArrayIndex.interval(0, 2)).mmul(s.get(NDArrayIndex.interval(0, 2), NDArrayIndex.all()));
        return reducedVectors;
    }
}

class Analyzer {
    private INDArray vectors;

    public Analyzer(INDArray vectors) {
        this.vectors = vectors;
    }

    public INDArray[] analyze() {
        INDArray means = vectors.mean(0);
        INDArray variances = vectors.var(0);
        return new INDArray[]{means, variances};
    }
}

public class sample_2029 {
    public static void main(String[] args) {
        List<String> data = new ArrayList<>();
        data.add("Example text");
        data.add("Another piece of text");
        data.add("Yet more text data");
        Vectorizer vectorizer = new Vectorizer(data);
        List<String> processedData = vectorizer.preprocess();
        INDArray vectors = vectorizer.vectorize(processedData);
        Processor processor = new Processor(vectors);
        INDArray normalizedVectors = processor.normalize(vectors);
        INDArray reducedVectors = processor.reduceDimensionality(normalizedVectors);
        Analyzer analyzer = new Analyzer(reducedVectors);
        INDArray[] results = analyzer.analyze();
        System.out.println("Means: " + results[0]);
        System.out.println("Variances: " + results[1]);
    }
}