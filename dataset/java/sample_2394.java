import java.util.ArrayList;
import java.util.List;

class Vector3D {
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

    double dot(Vector3D other) {
        return this.x * other.x + this.y * other.y + this.z * other.z;
    }

    Vector3D cross(Vector3D other) {
        return new Vector3D(this.y * other.z - this.z * other.y, this.z * other.x - this.x * other.z, this.x * other.y - this.y * other.x);
    }

    double magnitude() {
        return Math.sqrt(this.x * this.x + this.y * this.y + this.z * this.z);
    }

    Vector3D normalize() {
        double mag = this.magnitude();
        if (mag > 0) {
            return new Vector3D(this.x / mag, this.y / mag, this.z / mag);
        }
        return new Vector3D(0, 0, 0);
    }
}

class Transformation {
    double rotation;
    Vector3D translation;

    Transformation(double rotation, Vector3D translation) {
        this.rotation = rotation;
        this.translation = translation;
    }

    Vector3D apply(Vector3D vector) {
        Vector3D rotated = this.rotate(vector);
        return rotated.add(this.translation);
    }

    Vector3D rotate(Vector3D vector) {
        double x = vector.x, y = vector.y, z = vector.z;
        double cosTheta = Math.cos(this.rotation), sinTheta = Math.sin(this.rotation);
        double rx = x * cosTheta - z * sinTheta;
        double ry = y;
        double rz = x * sinTheta + z * cosTheta;
        return new Vector3D(rx, ry, rz);
    }
}

public class sample_2394 {
    static List<Vector3D> transformSequence(List<Vector3D> vectors, List<Transformation> transformations) {
        List<Vector3D> result = new ArrayList<>();
        for (Vector3D vector : vectors) {
            Vector3D transformed = vector;
            for (Transformation transformation : transformations) {
                transformed = transformation.apply(transformed);
            }
            result.add(transformed);
        }
        return result;
    }

    public static void main(String[] args) {
        List<Vector3D> vectors = List.of(new Vector3D(1, 0, 0), new Vector3D(0, 1, 0), new Vector3D(0, 0, 1));
        List<Transformation> transformations = List.of(
            new Transformation(Math.PI / 4, new Vector3D(1, 1, 1)),
            new Transformation(Math.PI / 6, new Vector3D(-1, -1, -1))
        );
        while (true) {
            List<Vector3D> transformedVectors = transformSequence(vectors, transformations);
            for (Vector3D v : transformedVectors) {
                System.out.printf("(%.6f, %.6f, %.6f)%n", v.x, v.y, v.z);
            }
        }
    }
}