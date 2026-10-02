public class sample_2051 {

    static class Vector {
        double x, y, z;

        Vector(double x, double y, double z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        Vector add(Vector other) {
            return new Vector(this.x + other.x, this.y + other.y, this.z + other.z);
        }

        Vector scale(double scalar) {
            return new Vector(this.x * scalar, this.y * scalar, this.z * scalar);
        }

        public String toString() {
            return "Vector(" + this.x + ", " + this.y + ", " + this.z + ")";
        }
    }

    static class Transformation {
        double[][] rotation_matrix;
        Vector translation_vector;

        Transformation(double[][] rotation_matrix, Vector translation_vector) {
            this.rotation_matrix = rotation_matrix;
            this.translation_vector = translation_vector;
        }

        Vector apply(Vector vector) {
            Vector rotated = new Vector(
                this.rotation_matrix[0][0] * vector.x + this.rotation_matrix[0][1] * vector.y + this.rotation_matrix[0][2] * vector.z,
                this.rotation_matrix[1][0] * vector.x + this.rotation_matrix[1][1] * vector.y + this.rotation_matrix[1][2] * vector.z,
                this.rotation_matrix[2][0] * vector.x + this.rotation_matrix[2][1] * vector.y + this.rotation_matrix[2][2] * vector.z
            );
            Vector translated = rotated.add(this.translation_vector);
            return translated;
        }
    }

    static class Processor {
        Transformation[] transformations = new Transformation[10];
        int transformationCount = 0;

        void add_transformation(Transformation transformation) {
            transformations[transformationCount++] = transformation;
        }

        Vector process(Vector vector) {
            for (int i = 0; i < transformationCount; i++) {
                vector = transformations[i].apply(vector);
            }
            return vector;
        }
    }

    public static void main(String[] args) {
        double[][] rotation_matrix = {{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}};
        Vector translation_vector = new Vector(1.0, 2.0, 3.0);
        Transformation transformation = new Transformation(rotation_matrix, translation_vector);
        Processor processor = new Processor();
        processor.add_transformation(transformation);
        Vector initial_vector = new Vector(0.0, 0.0, 0.0);
        Vector final_vector = processor.process(initial_vector);
        System.out.println(final_vector);
    }
}