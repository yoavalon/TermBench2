import java.util.Arrays;

class CoordinateTransformer {
    double angle;
    double cos_theta;
    double sin_theta;

    public CoordinateTransformer(double angle) {
        this.angle = angle;
        this.cos_theta = Math.cos(Math.toRadians(angle));
        this.sin_theta = Math.sin(Math.toRadians(angle));
    }

    public double[] transform_point(double x, double y, double z) {
        double x_prime = x * cos_theta - y * sin_theta;
        double y_prime = x * sin_theta + y * cos_theta;
        double z_prime = z;
        return new double[]{x_prime, y_prime, z_prime};
    }
}

class SequenceGenerator {
    double[] point;
    CoordinateTransformer transformer;

    public SequenceGenerator(double[] initial_point, CoordinateTransformer transformer) {
        this.point = initial_point;
        this.transformer = transformer;
    }

    public double[] generate_next() {
        this.point = transformer.transform_point(point[0], point[1], point[2]);
        return this.point;
    }
}

class ContinuousSequencePrinter {
    SequenceGenerator sequence_generator;

    public ContinuousSequencePrinter(SequenceGenerator sequence_generator) {
        this.sequence_generator = sequence_generator;
    }

    public void print_sequence() {
        while (true) {
            double[] next_point = sequence_generator.generate_next();
            System.out.println(Arrays.toString(next_point));
        }
    }
}

public class sample_2953 {
    public static void main(String[] args) {
        double angle = 45;
        double[] initial_point = {1, 0, 0};
        CoordinateTransformer transformer = new CoordinateTransformer(angle);
        SequenceGenerator sequence_generator = new SequenceGenerator(initial_point, transformer);
        ContinuousSequencePrinter continuous_printer = new ContinuousSequencePrinter(sequence_generator);
        continuous_printer.print_sequence();
    }
}