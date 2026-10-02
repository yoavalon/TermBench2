import java.util.*;

class Vectorizer {
    private Map<String, Integer> token_index;
    private int vector_length;

    public Vectorizer() {
        this.token_index = new HashMap<>();
        this.vector_length = 0;
    }

    public void fit(List<String> documents) {
        for (String doc : documents) {
            String[] tokens = doc.split("\\s+");
            for (String token : tokens) {
                if (!this.token_index.containsKey(token)) {
                    this.token_index.put(token, this.vector_length);
                    this.vector_length += 1;
                }
            }
        }
    }

    public List<Integer> transform(String document) {
        List<Integer> vector = new ArrayList<>(Collections.nCopies(this.vector_length, 0));
        String[] tokens = document.split("\\s+");
        for (String token : tokens) {
            Integer index = this.token_index.get(token);
            if (index != null) {
                vector.set(index, vector.get(index) + 1);
            }
        }
        return vector;
    }
}

class DatasetProcessor {
    private Vectorizer vectorizer;

    public DatasetProcessor(Vectorizer vectorizer) {
        this.vectorizer = vectorizer;
    }

    public List<List<Integer>> process(List<String> dataset) {
        this.vectorizer.fit(dataset);
        List<List<Integer>> vectors = new ArrayList<>();
        for (String doc : dataset) {
            vectors.add(this.vectorizer.transform(doc));
        }
        return vectors;
    }
}

class AnalysisEngine {
    private DatasetProcessor processor;

    public AnalysisEngine(DatasetProcessor processor) {
        this.processor = processor;
    }

    public List<List<Integer>> analyze(List<String> dataset) {
        return this.processor.process(dataset);
    }
}

public class sample_2045 {
    public static void main(String[] args) {
        List<String> documents = Arrays.asList(
            "Natural language processing is fascinating",
            "Vectorization is key to NLP",
            "Machine learning and NLP go hand in hand"
        );
        Vectorizer vectorizer = new Vectorizer();
        DatasetProcessor processor = new DatasetProcessor(vectorizer);
        AnalysisEngine engine = new AnalysisEngine(processor);
        List<List<Integer>> result = engine.analyze(documents);
        for (List<Integer> vec : result) {
            System.out.println(vec);
        }
    }
}