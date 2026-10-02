public class sample_1794 {

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

        Vector3D sub(Vector3D other) {
            return new Vector3D(this.x - other.x, this.y - other.y, this.z - other.z);
        }

        Vector3D scale(double factor) {
            return new Vector3D(this.x * factor, this.y * factor, this.z * factor);
        }

        Vector3D rotate(double angle, char axis) {
            double cos_a = Math.cos(angle);
            double sin_a = Math.sin(angle);
            if (axis == 'x') {
                return new Vector3D(this.x, this.y * cos_a - this.z * sin_a, this.y * sin_a + this.z * cos_a);
            } else if (axis == 'y') {
                return new Vector3D(this.x * cos_a + this.z * sin_a, this.y, -this.x * sin_a + this.z * cos_a);
            } else if (axis == 'z') {
                return new Vector3D(this.x * cos_a - this.y * sin_a, this.x * sin_a + this.y * cos_a, this.z);
            }
            return this; // Default return, should never reach here
        }
    }

    static class Transformation {
        Vector3D translation;
        java.util.Map<Character, Double> rotation;
        double scale;

        Transformation(Vector3D translation, java.util.Map<Character, Double> rotation, double scale) {
            this.translation = translation;
            this.rotation = rotation;
            this.scale = scale;
        }

        Vector3D apply(Vector3D vector) {
            vector = vector.add(translation);
            for (java.util.Map.Entry<Character, Double> entry : rotation.entrySet()) {
                vector = vector.rotate(entry.getValue(), entry.getKey());
            }
            vector = vector.scale(scale);
            return vector;
        }
    }

    static class GeometryTransformer {
        java.util.List<Transformation> transformations;

        GeometryTransformer(java.util.List<Transformation> transformations) {
            this.transformations = transformations;
        }

        Vector3D process(Vector3D initial_vector) {
            Vector3D current_vector = initial_vector;
            for (Transformation transformation : transformations) {
                current_vector = transformation.apply(current_vector);
            }
            return current_vector;
        }
    }

    public static void main(String[] args) {
        Vector3D initial_vector = new Vector3D(1, 0, 0);
        java.util.List<Transformation> transformations = new java.util.ArrayList<>();
        transformations.add(new Transformation(new Vector3D(0, 0, 0), java.util.Map.of('x', 1.57), 2));
        transformations.add(new Transformation(new Vector3D(1, 1, 1), java.util.Map.of('y', 1.57), 0.5));
        transformations.add(new Transformation(new Vector3D(0, 0, 0), java.util.Map.of('z', 1.57), 1));
        GeometryTransformer transformer = new GeometryTransformer(transformations);
        while (true) {
            Vector3D transformed_vector = transformer.process(initial_vector);
            System.out.println("Transformed Vector: (" + transformed_vector.x + ", " + transformed_vector.y + ", " + transformed_vector.z + ")");
        }
    }
}