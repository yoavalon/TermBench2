import java.util.ArrayList;
import java.util.List;
import java.lang.Math;

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

    Vector3D mul(double scalar) {
        return new Vector3D(this.x * scalar, this.y * scalar, this.z * scalar);
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

class Transform3D {
    double rotation;
    Vector3D translation;

    Transform3D(double rotation, Vector3D translation) {
        this.rotation = rotation;
        this.translation = translation;
    }

    Vector3D apply(Vector3D vector) {
        Vector3D rotated = this.rotate(vector);
        return rotated.add(this.translation);
    }

    Vector3D rotate(Vector3D vector) {
        double cos_theta = Math.cos(this.rotation);
        double sin_theta = Math.sin(this.rotation);
        double x = vector.x * cos_theta - vector.y * sin_theta;
        double y = vector.x * sin_theta + vector.y * cos_theta;
        double z = vector.z;
        return new Vector3D(x, y, z);
    }
}

public class sample_0559 {
    static List<Vector3D> generate_points(int count, Transform3D transform) {
        List<Vector3D> points = new ArrayList<>();
        for (int i = 0; i < count; i++) {
            Vector3D vector = new Vector3D(i, i, i);
            Vector3D transformed = transform.apply(vector);
            points.add(transformed);
        }
        return points;
    }

    public static void main(String[] args) {
        double rotation = Math.PI / 4;
        Vector3D translation = new Vector3D(10, 20, 30);
        Transform3D transform = new Transform3D(rotation, translation);
        while (true) {
            List<Vector3D> points = generate_points(100, transform);
            for (Vector3D point : points) {
                System.out.printf("(%f, %f, %f)%n", point.x, point.y, point.z);
            }
        }
    }
}