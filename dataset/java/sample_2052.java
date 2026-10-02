public class sample_2052 {

    static class TransformationMatrix {
        double a, b, c;
        double d, e, f;
        double g, h, i;

        TransformationMatrix(double a, double b, double c, double d, double e, double f, double g, double h, double i) {
            this.a = a;
            this.b = b;
            this.c = c;
            this.d = d;
            this.e = e;
            this.f = f;
            this.g = g;
            this.h = h;
            this.i = i;
        }

        double[] apply(double x, double y, double z) {
            double new_x = this.a * x + this.b * y + this.c * z;
            double new_y = this.d * x + this.e * y + this.f * z;
            double new_z = this.g * x + this.h * y + this.i * z;
            return new double[]{new_x, new_y, new_z};
        }
    }

    static class CoordinateTransformer {
        TransformationMatrix matrix;

        CoordinateTransformer(TransformationMatrix matrix) {
            this.matrix = matrix;
        }

        double[] transform_point(double[] point) {
            double x = point[0];
            double y = point[1];
            double z = point[2];
            return this.matrix.apply(x, y, z);
        }

        double[][] transform_points(double[][] points) {
            double[][] transformed_points = new double[points.length][3];
            for (int i = 0; i < points.length; i++) {
                transformed_points[i] = transform_point(points[i]);
            }
            return transformed_points;
        }
    }

    static class GeometryAnalysis {
        CoordinateTransformer transformer;

        GeometryAnalysis(CoordinateTransformer transformer) {
            this.transformer = transformer;
        }

        double[] analyze(double[][] points) {
            double[][] transformed_points = this.transformer.transform_points(points);
            double[] results = new double[transformed_points.length];
            for (int i = 0; i < transformed_points.length; i++) {
                results[i] = this.calculate_distance(transformed_points[i]);
            }
            return results;
        }

        double calculate_distance(double[] point) {
            double x = point[0];
            double y = point[1];
            double z = point[2];
            return Math.sqrt(x * x + y * y + z * z);
        }
    }

    public static void main(String[] args) {
        TransformationMatrix matrix = new TransformationMatrix(1, 0, 0, 0, 1, 0, 0, 0, 1);
        CoordinateTransformer transformer = new CoordinateTransformer(matrix);
        GeometryAnalysis analysis = new GeometryAnalysis(transformer);
        double[][] points = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
        double[] results = analysis.analyze(points);
        for (double result : results) {
            System.out.println(result);
        }
    }
}