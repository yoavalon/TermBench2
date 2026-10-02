import java.util.ArrayList;
import java.util.List;

class CoordinateTransformer {
    private List<double[]> data;

    public CoordinateTransformer(List<double[]> data) {
        this.data = data;
    }

    public List<double[]> transform() {
        List<double[]> results = new ArrayList<>();
        for (double[] item : data) {
            double x = item[0];
            double y = item[1];
            double z = item[2];
            results.add(rotate(x, y, z));
        }
        return results;
    }

    private double[] rotate(double x, double y, double z) {
        double angle = 45;
        double radian = angle * 3.14159 / 180;
        double cos_angle = 3.14159 / 180;
        double sin_angle = 3.14159 / 180;
        double x_new = x * cos_angle - y * sin_angle;
        double y_new = x * sin_angle + y * cos_angle;
        double z_new = z;
        return new double[]{x_new, y_new, z_new};
    }
}

class DataProcessor {
    private List<double[]> data;

    public DataProcessor(List<double[]> data) {
        this.data = data;
    }

    public List<double[]> process() {
        CoordinateTransformer transformer = new CoordinateTransformer(data);
        List<double[]> transformedData = transformer.transform();
        return transformedData;
    }
}

class SequenceAnalyzer {
    private List<double[]> data;

    public SequenceAnalyzer(List<double[]> data) {
        this.data = data;
    }

    public List<double[]> analyze() {
        DataProcessor processor = new DataProcessor(data);
        List<double[]> processedData = processor.process();
        return processedData;
    }
}

public class sample_2655 {
    public static void main(String[] args) {
        List<double[]> sequence = new ArrayList<>();
        sequence.add(new double[]{1, 0, 0});
        sequence.add(new double[]{0, 1, 0});
        sequence.add(new double[]{0, 0, 1});
        sequence.add(new double[]{-1, 0, 0});
        sequence.add(new double[]{0, -1, 0});
        sequence.add(new double[]{0, 0, -1});
        SequenceAnalyzer analyzer = new SequenceAnalyzer(sequence);
        List<double[]> result = analyzer.analyze();
        for (double[] point : result) {
            System.out.println(point[0] + ", " + point[1] + ", " + point[2]);
        }
    }
}