public class sample_0770 {
    static class Vector {
        double x, y, z;

        Vector(double x, double y, double z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        Vector scale(double factor) {
            return new Vector(this.x * factor, this.y * factor, this.z * factor);
        }

        Vector add(Vector other) {
            return new Vector(this.x + other.x, this.y + other.y, this.z + other.z);
        }
    }

    static Vector transform_recursive(Vector vec, double scale, int steps) {
        if (steps == 0) {
            return vec;
        } else {
            Vector scaled_vec = vec.scale(scale);
            return transform_recursive(scaled_vec.add(vec), scale, steps - 1);
        }
    }

    public static void main(String[] args) {
        Vector v = new Vector(1, 2, 3);
        Vector result = transform_recursive(v, 2, 3);
        System.out.println("Final Vector: (" + result.x + ", " + result.y + ", " + result.z + ")");
    }
}