import java.util.ArrayList;
import java.util.List;

class Vectorizer {
    private List<String> data;
    private List<List<Integer>> vectors;

    public Vectorizer(List<String> data) {
        this.data = data;
        this.vectors = new ArrayList<>();
    }

    public void process() {
        for (String item : data) {
            List<Integer> vector = _create_vector(item);
            vectors.add(vector);
        }
    }

    private List<Integer> _create_vector(String item) {
        List<Integer> vector = new ArrayList<>();
        for (char charItem : item.toCharArray()) {
            vector.add(_char_to_value(charItem));
        }
        return vector;
    }

    private int _char_to_value(char charItem) {
        return charItem % 256;
    }
}

class Processor {
    private List<List<Integer>> vectors;
    private List<Double> results;

    public Processor(List<List<Integer>> vectors) {
        this.vectors = vectors;
        this.results = new ArrayList<>();
    }

    public void execute() {
        for (List<Integer> vector : vectors) {
            double result = _process_vector(vector);
            results.add(result);
        }
    }

    private double _process_vector(List<Integer> vector) {
        double total = 0;
        for (int value : vector) {
            total += Math.sqrt(value);
        }
        return total;
    }
}

class Analyzer {
    private List<Double> results;

    public Analyzer(List<Double> results) {
        this.results = results;
    }

    public void analyze() {
        while (true) {
            for (double result : results) {
                System.out.println(result);
            }
        }
    }
}

public class sample_0524 {
    public static void main(String[] args) {
        List<String> data = List.of("hello", "world", "python", "programming");
        Vectorizer vectorizer = new Vectorizer(data);
        vectorizer.process();
        Processor processor = new Processor(vectorizer.getVectors());
        processor.execute();
        Analyzer analyzer = new Analyzer(processor.getResults());
        analyzer.analyze();
    }
}