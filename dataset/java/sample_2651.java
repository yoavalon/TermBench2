public class sample_2651 {

    static class Vector3D {
        double x, y, z;

        Vector3D(double x, double y, double z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        Vector3D add(Vector3D other) {
            return new Vector3D(this.x + other.x, this.y + other.y, this.z + other.z);
        }

        Vector3D subtract(Vector3D other) {
            return new Vector3D(this.x - other.x, this.y - other.y, this.z - other.z);
        }

        Vector3D scale(double scalar) {
            return new Vector3D(this.x * scalar, this.y * scalar, this.z * scalar);
        }

        double magnitude() {
            return Math.sqrt(this.x * this.x + this.y * this.y + this.z * this.z);
        }
    }

    static class Transformation {
        double[][] rotation_matrix;
        Vector3D translation_vector;

        Transformation(double[][] rotation_matrix, Vector3D translation_vector) {
            this.rotation_matrix = rotation_matrix;
            this.translation_vector = translation_vector;
        }

        Vector3D apply(Vector3D vector) {
            double x = vector.x * rotation_matrix[0][0] + vector.y * rotation_matrix[0][1] + vector.z * rotation_matrix[0][2];
            double y = vector.x * rotation_matrix[1][0] + vector.y * rotation_matrix[1][1] + vector.z * rotation_matrix[1][2];
            double z = vector.x * rotation_matrix[2][0] + vector.y * rotation_matrix[2][1] + vector.z * rotation_matrix[2][2];
            Vector3D translated_vector = new Vector3D(x, y, z).add(translation_vector);
            return translated_vector;
        }
    }

    static Vector3D[] generate_sequence(Vector3D start, Transformation transformation, int steps) {
        Vector3D[] sequence = new Vector3D[steps];
        Vector3D current_vector = start;
        for (int i = 0; i < steps; i++) {
            sequence[i] = current_vector;
            current_vector = transformation.apply(current_vector);
        }
        return sequence;
    }

    public static void main(String[] args) {
        Vector3D start_vector = new Vector3D(1, 0, 0);
        double[][] rotation_matrix = {{0, -1, 0}, {1, 0, 0}, {0, 0, 1}};
        Vector3D translation_vector = new Vector3D(1, 1, 1);
        Transformation transformation = new Transformation(rotation_matrix, translation_vector);
        Vector3D[] sequence = generate_sequence(start_vector, transformation, 10);
        for (Vector3D vector : sequence) {
            System.out.printf("(%.1f, %.1f, %.1f)%n", vector.x, vector.y, vector.z);
        }
    }
}