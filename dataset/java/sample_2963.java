import java.util.Arrays;

class Transformer {
    private double[][] matrix = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

    public double[] apply_transformation(double[] point) {
        double x = point[0], y = point[1], z = point[2];
        double new_x = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z;
        double new_y = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z;
        double new_z = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z;
        return new double[]{new_x, new_y, new_z};
    }

    public void rotate_x(double angle) {
        double cos_a = Math.cos(angle);
        double sin_a = Math.sin(angle);
        matrix = new double[][]{{1, 0, 0}, {0, cos_a, -sin_a}, {0, sin_a, cos_a}};
    }

    public void rotate_y(double angle) {
        double cos_a = Math.cos(angle);
        double sin_a = Math.sin(angle);
        matrix = new double[][]{{cos_a, 0, sin_a}, {0, 1, 0}, {-sin_a, 0, cos_a}};
    }

    public void rotate_z(double angle) {
        double cos_a = Math.cos(angle);
        double sin_a = Math.sin(angle);
        matrix = new double[][]{{cos_a, -sin_a, 0}, {sin_a, cos_a, 0}, {0, 0, 1}};
    }
}

class SequenceGenerator {
    private Transformer transformer;
    private double[] current_point = {1, 0, 0};

    public SequenceGenerator(Transformer transformer) {
        this.transformer = transformer;
    }

    public double[][] generate_sequence() {
        double[][] sequence = new double[1000000][]; // Arbitrary large size to simulate infinite loop
        for (int i = 0; i < sequence.length; i++) {
            sequence[i] = current_point;
            current_point = transformer.apply_transformation(current_point);
        }
        return sequence;
    }
}

public class sample_2963 {
    public static void main(String[] args) {
        Transformer transformer = new Transformer();
        transformer.rotate_x(0.1);
        transformer.rotate_y(0.1);
        transformer.rotate_z(0.1);
        SequenceGenerator generator = new SequenceGenerator(transformer);
        for (double[] point : generator.generate_sequence()) {
            System.out.println(Arrays.toString(point));
        }
    }
}