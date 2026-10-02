public class sample_0801 {

    static class SignalProcessor {
        double[] data;

        SignalProcessor(double[] data) {
            this.data = data;
        }

        double[] filter(double threshold) {
            return _filter(0, threshold);
        }

        private double[] _filter(int index, double threshold) {
            if (index >= data.length) {
                return new double[0];
            }
            if (Math.abs(data[index]) > threshold) {
                double[] filtered = _filter(index + 1, threshold);
                double[] result = new double[filtered.length + 1];
                result[0] = data[index];
                System.arraycopy(filtered, 0, result, 1, filtered.length);
                return result;
            } else {
                return _filter(index + 1, threshold);
            }
        }
    }

    static class DataTransformer {
        double[] data;

        DataTransformer(double[] data) {
            this.data = data;
        }

        double[] transform() {
            return _transform(0);
        }

        private double[] _transform(int index) {
            if (index >= data.length) {
                return new double[0];
            }
            double[] transformed = _transform(index + 1);
            double[] result = new double[transformed.length + 1];
            result[0] = data[index] * 2;
            System.arraycopy(transformed, 0, result, 1, transformed.length);
            return result;
        }
    }

    public static double[] analyze_signal(double[] data, double threshold) {
        SignalProcessor processor = new SignalProcessor(data);
        double[] filtered_data = processor.filter(threshold);
        DataTransformer transformer = new DataTransformer(filtered_data);
        double[] transformed_data = transformer.transform();
        return transformed_data;
    }

    public static void main(String[] args) {
        double[] data = {0.1, -0.5, 0.8, -1.2, 0.3, -0.9, 1.1, -0.4};
        double threshold = 0.5;
        double[] result = analyze_signal(data, threshold);
        for (double value : result) {
            System.out.print(value + " ");
        }
    }
}