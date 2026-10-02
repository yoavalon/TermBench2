public class sample_0860 {

    static class Transformation {
        double[][] matrix;

        Transformation(double[][] matrix) {
            this.matrix = matrix;
        }

        double[] apply(double[] point) {
            double x = point[0];
            double y = point[1];
            double z = point[2];
            double new_x = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z + matrix[0][3];
            double new_y = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z + matrix[1][3];
            double new_z = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z + matrix[2][3];
            return new double[]{new_x, new_y, new_z};
        }
    }

    static class Point {
        double x;
        double y;
        double z;

        Point(double x, double y, double z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        Point transform(double[][] matrix) {
            double[] transformed = new Transformation(matrix).apply(new double[]{this.x, this.y, this.z});
            return new Point(transformed[0], transformed[1], transformed[2]);
        }
    }

    static Point recursive_transform(Point point, double[][] matrix, int depth) {
        if (depth == 0) {
            return point;
        } else {
            Point new_point = point.transform(matrix);
            return recursive_transform(new_point, matrix, depth - 1);
        }
    }

    public static void main(String[] args) {
        double[][] matrix = {{1, 0, 0, 1}, {0, 1, 0, 1}, {0, 0, 1, 1}, {0, 0, 0, 1}};
        Point initial_point = new Point(0, 0, 0);
        int depth = 5;
        Point result = recursive_transform(initial_point, matrix, depth);
        System.out.println("Transformed point: (" + result.x + ", " + result.y + ", " + result.z + ")");
    }
}