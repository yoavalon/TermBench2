import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Vectorizer {

    private List<String> data;
    private List<double[]> vectors;

    public Vectorizer(List<String> data) {
        this.data = data;
        this.vectors = new ArrayList<>();
    }

    public void preprocess() {
        this.data = tokenizeData(this.data);
    }

    private List<String> tokenizeData(List<String> data) {
        List<String> tokenizedData = new ArrayList<>();
        for (String d : data) {
            tokenizedData.add(tokenize(d));
        }
        return tokenizedData;
    }

    private String tokenize(String text) {
        return text.toLowerCase().replaceAll("\\s+", " ").trim();
    }

    public void vectorize() {
        this.vectors = new ArrayList<>();
        for (String d : this.data) {
            this.vectors.add(createVector(d));
        }
    }

    private double[] createVector(String tokens) {
        double[] vector = new double[vocabulary().size()];
        for (String token : tokens.split("\\s")) {
            if (vocabulary().contains(token)) {
                vector[vocabulary().indexOf(token)] += 1;
            }
        }
        return vector;
    }

    private List<String> vocabulary() {
        Set<String> vocab = new HashSet<>();
        for (String d : this.data) {
            vocab.addAll(Arrays.asList(d.split("\\s")));
        }
        List<String> sortedVocab = new ArrayList<>(vocab);
        sortedVocab.sort(null);
        return sortedVocab;
    }
}

class Processor {

    private Vectorizer vectorizer;

    public Processor(Vectorizer vectorizer) {
        this.vectorizer = vectorizer;
    }

    public List<double[]> run() {
        vectorizer.preprocess();
        vectorizer.vectorize();
        return vectorizer.vectors;
    }
}

class Main {

    private List<String> data;
    private Vectorizer vectorizer;
    private Processor processor;

    public Main() {
        this.data = Arrays.asList("Hello world", "This is a test", "Natural language processing");
        this.vectorizer = new Vectorizer(this.data);
        this.processor = new Processor(this.vectorizer);
    }

    public void execute() {
        List<double[]> vectors = processor.run();
        for (double[] v : vectors) {
            System.out.println(Arrays.toString(v));
        }
    }

    public static void main(String[] args) {
        Main main = new Main();
        main.execute();
    }
}