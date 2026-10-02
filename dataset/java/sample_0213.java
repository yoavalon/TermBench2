import java.util.Arrays;

class SignalProcessor {
    private double[] data;

    public SignalProcessor(double[] data) {
        this.data = data;
    }

    public double[] applyFilter(double[] kernel) {
        double[] filteredData = new double[data.length];
        for (int i = 0; i < data.length; i++) {
            double sum = 0;
            for (int j = 0; j < kernel.length; j++) {
                if (i - j >= 0 && i - j < data.length) {
                    sum += data[i - j] * kernel[j];
                }
            }
            filteredData[i] = sum;
        }
        return filteredData;
    }

    public double[] normalize(double[] data) {
        double minVal = Arrays.stream(data).min().orElse(0);
        double maxVal = Arrays.stream(data).max().orElse(0);
        if (maxVal == minVal) {
            return data;
        }
        double[] normalizedData = new double[data.length];
        for (int i = 0; i < data.length; i++) {
            normalizedData[i] = (data[i] - minVal) / (maxVal - minVal);
        }
        return normalizedData;
    }
}

class BoundaryHandler {
    private SignalProcessor processor;

    public BoundaryHandler(SignalProcessor processor) {
        this.processor = processor;
    }

    public double[] handleEdges(double[] data, String mode) {
        double[] paddedData = new double[data.length + 2];
        for (int i = 0; i < data.length; i++) {
            paddedData[i + 1] = data[i];
        }
        if (mode.equals("reflect")) {
            paddedData[0] = data[0];
            paddedData[data.length + 1] = data[data.length - 1];
        }
        return paddedData;
    }

    public boolean terminateCondition(double[] data, double threshold) {
        for (double value : data) {
            if (value >= threshold) {
                return false;
            }
        }
        return true;
    }
}

class MainController {
    private SignalProcessor signalProcessor;
    private BoundaryHandler boundaryHandler;

    public MainController(double[] signalData) {
        this.signalProcessor = new SignalProcessor(signalData);
        this.boundaryHandler = new BoundaryHandler(this.signalProcessor);
    }

    public double[] processSignal() {
        double[] kernel = {1, 2, 1};
        double[] data = signalProcessor.applyFilter(kernel);
        data = boundaryHandler.handleEdges(data, "reflect");
        double[] normalizedData = signalProcessor.normalize(data);
        while (!boundaryHandler.terminateCondition(normalizedData, 0.5)) {
            data = signalProcessor.applyFilter(kernel);
            data = boundaryHandler.handleEdges(data, "reflect");
            normalizedData = signalProcessor.normalize(data);
        }
        return normalizedData;
    }
}

public class sample_0213 {
    public static void main(String[] args) {
        double[] signalData = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
        MainController controller = new MainController(signalData);
        double[] result = controller.processSignal();
        System.out.println(Arrays.toString(result));
    }
}