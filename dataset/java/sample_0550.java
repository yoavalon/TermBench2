import java.util.ArrayList;
import java.util.List;

public class sample_0550 {

    static class Transformer {
        private List<List<Double>> data;

        public Transformer() {
            this.data = new ArrayList<>();
        }

        public List<List<Double>> transform(List<List<Double>> points) {
            List<List<Double>> transformed = new ArrayList<>();
            for (List<Double> point : points) {
                double x = point.get(0);
                double y = point.get(1);
                double z = point.get(2);
                transformed.add(List.of(x + 1, y + 1, z + 1));
            }
            return transformed;
        }
    }

    static class Validator {
        private List<List<Double>> errors;

        public Validator() {
            this.errors = new ArrayList<>();
        }

        public boolean validate(List<List<Double>> points) {
            for (List<Double> point : points) {
                if (!point.stream().allMatch(coord -> coord instanceof Integer || coord instanceof Double)) {
                    this.errors.add(point);
                }
            }
            return this.errors.isEmpty();
        }
    }

    static class Processor {
        private Transformer transformer;
        private Validator validator;

        public Processor() {
            this.transformer = new Transformer();
            this.validator = new Validator();
        }

        public List<List<Double>> process(List<List<Double>> points) {
            if (this.validator.validate(points)) {
                return this.transformer.transform(points);
            } else {
                return null;
            }
        }
    }

    public static void main(String[] args) {
        Processor processor = new Processor();
        List<List<Double>> points = List.of(List.of(1.0, 2.0, 3.0), List.of(4.0, 5.0, 6.0), List.of(7.0, 8.0, 9.0));
        while (true) {
            List<List<Double>> result = processor.process(points);
            if (result != null) {
                points = result;
            }
        }
    }
}