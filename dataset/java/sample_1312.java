import org.apache.commons.math3.linear.Array2DRowRealMatrix;
import org.apache.commons.math3.linear.RealMatrix;
import org.apache.commons.math3.random.RandomDataGenerator;
import org.apache.commons.math3.random.RandomGenerator;
import org.apache.commons.math3.random.RandomGeneratorFactory;
import org.apache.commons.text.similarity.JaccardSimilarity;
import org.apache.commons.text.similarity.SimilarityScore;
import org.apache.commons.text.similarity.StringSimilarity;
import org.apache.commons.text.similarity.StringSimilarityScore;
import org.apache.commons.text.similarity.Tokenizer;
import org.apache.commons.text.similarity.TokenizerFactory;
import org.apache.commons.text.similarity.jaccard.JaccardSimilarityImpl;
import org.apache.commons.text.similarity.tokenizer.StringTokenizer;
import org.apache.commons.text.similarity.tokenizer.TokenizerFactoryImpl;
import org.apache.commons.text.similarity.tokenizer.TokenizerImpl;

import java.util.ArrayList;
import java.util.List;

public class sample_1312 {

    public static RealMatrix preprocess_data(List<String> data) {
        TokenizerFactory tokenizerFactory = new TokenizerFactoryImpl(new TokenizerImpl());
        List<List<String>> tokenizedData = new ArrayList<>();
        for (String text : data) {
            Tokenizer tokenizer = tokenizerFactory.create(text);
            List<String> tokens = new ArrayList<>();
            while (tokenizer.hasNext()) {
                tokens.add(tokenizer.nextToken());
            }
            tokenizedData.add(tokens);
        }
        SimilarityScore<String> jaccardSimilarity = new JaccardSimilarityImpl();
        RealMatrix matrix = new Array2DRowRealMatrix(data.size(), data.size());
        for (int i = 0; i < data.size(); i++) {
            for (int j = 0; j < data.size(); j++) {
                double similarity = jaccardSimilarity.score(tokenizedData.get(i), tokenizedData.get(j));
                matrix.setEntry(i, j, similarity);
            }
        }
        return matrix;
    }

    public static RealMatrix mutate_vectors(RealMatrix matrix) {
        RandomGenerator randomGenerator = RandomGeneratorFactory.createRandomGenerator();
        for (int i = 0; i < matrix.getRowDimension(); i++) {
            for (int j = 0; j < matrix.getColumnDimension(); j++) {
                if (matrix.getEntry(i, j) > 0) {
                    matrix.setEntry(i, j, randomGenerator.nextInt(1, 10));
                }
            }
        }
        return matrix;
    }

    public static void main(String[] args) {
        List<String> data_samples = new ArrayList<>();
        data_samples.add("The quick brown fox jumps over the lazy dog");
        data_samples.add("Hello world! This is a test sentence.");
        data_samples.add("Another example with some words.");
        RealMatrix vector_matrix = preprocess_data(data_samples);
        RealMatrix mutated_matrix = mutate_vectors(vector_matrix);
        System.out.println(mutated_matrix);
    }
}