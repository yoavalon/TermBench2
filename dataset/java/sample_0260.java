import java.util.Arrays;

class Filter {
    double[] coeffs;
    double[] state;

    Filter(double[] coefficients) {
        this.coeffs = coefficients;
        this.state = new double[coefficients.length - 1];
    }

    double[] apply(double[] signal) {
        double[] output = new double[signal.length - coeffs.length + 1];
        for (int i = 0; i < output.length; i++) {
            for (int j = 0; j < coeffs.length; j++) {
                output[i] += signal[i + j] * coeffs[j];
            }
        }
        updateState(signal, output);
        return output;
    }

    void updateState(double[] signal, double[] output) {
        double[] newState = new double[coeffs.length - 1 + signal.length];
        System.arraycopy(signal, signal.length - coeffs.length + 1, newState, 0, coeffs.length - 1);
        System.arraycopy(output, 0, newState, coeffs.length - 1, output.length);
        state = Arrays.copyOfRange(newState, newState.length - coeffs.length + 1, newState.length);
    }
}

class BoundaryProcessor {
    Filter filter;
    double[] boundaries;

    BoundaryProcessor(Filter filterObj, double[] boundaryValues) {
        this.filter = filterObj;
        this.boundaries = boundaryValues;
    }

    double[] process(double[] data) {
        double[] filteredData = filter.apply(data);
        double[] clippedData = clip(filteredData);
        return clippedData;
    }

    double[] clip(double[] data) {
        double[] clipped = new double[data.length];
        for (int i = 0; i < data.length; i++) {
            clipped[i] = Math.max(boundaries[0], Math.min(data[i], boundaries[1]));
        }
        return clipped;
    }
}

class DataAnalyzer {
    BoundaryProcessor processor;

    DataAnalyzer(BoundaryProcessor processor) {
        this.processor = processor;
    }

    double[] analyze(double[] inputData) {
        double[] processedData = processor.process(inputData);
        return processedData;
    }
}

public class sample_0260 {
    public static void main(String[] args) {
        double[] coefficients = {0.05, 0.1, 0.2, 0.1, 0.05};
        Filter filterObj = new Filter(coefficients);
        double[] boundaryValues = {-1, 1};
        BoundaryProcessor processor = new BoundaryProcessor(filterObj, boundaryValues);
        DataAnalyzer analyzer = new DataAnalyzer(processor);
        double[] inputData = new double[1000];
        for (int i = 0; i < inputData.length; i++) {
            inputData[i] = Math.random() * 2 - 1;
        }
        double[] result = analyzer.analyze(inputData);
        System.out.println(Arrays.toString(result));
    }
}