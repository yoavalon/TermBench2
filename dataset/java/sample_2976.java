import java.util.Arrays;

class Coordinate {

    double x, y, z;

    Coordinate(double x, double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    Coordinate rotate(double angle_x, double angle_y, double angle_z) {
        double rad_x = Math.toRadians(angle_x);
        double rad_y = Math.toRadians(angle_y);
        double rad_z = Math.toRadians(angle_z);
        double cos_x = Math.cos(rad_x), sin_x = Math.sin(rad_x);
        double cos_y = Math.cos(rad_y), sin_y = Math.sin(rad_y);
        double cos_z = Math.cos(rad_z), sin_z = Math.sin(rad_z);
        double nx = this.x * cos_y * cos_z + this.y * (sin_x * sin_y * cos_z - cos_x * sin_z) + this.z * (cos_x * sin_y * cos_z + sin_x * sin_z);
        double ny = this.x * cos_y * sin_z + this.y * (sin_x * sin_y * sin_z + cos_x * cos_z) + this.z * (cos_x * sin_y * sin_z - sin_x * cos_z);
        double nz = -this.x * sin_y + this.y * sin_x * cos_y + this.z * cos_x * cos_y;
        return new Coordinate(nx, ny, nz);
    }
}

class SequenceGenerator {

    Coordinate origin;
    double[][] angles;
    int index = 0;

    SequenceGenerator(Coordinate origin, double[][] angles) {
        this.origin = origin;
        this.angles = angles;
    }

    Coordinate next() {
        double[] angles = this.angles[index % this.angles.length];
        Coordinate transformed = origin.rotate(angles[0], angles[1], angles[2]);
        index++;
        return transformed;
    }
}

class Transformer {

    SequenceGenerator sequence_generator;

    Transformer(SequenceGenerator sequence_generator) {
        this.sequence_generator = sequence_generator;
    }

    void transform() {
        while (true) {
            Coordinate point = sequence_generator.next();
            System.out.printf("Transformed Coordinates: (%.2f, %.2f, %.2f)%n", point.x, point.y, point.z);
        }
    }
}

public class sample_2976 {
    public static void main(String[] args) {
        Coordinate origin = new Coordinate(1, 0, 0);
        double[][] angles = {{0, 0, 10}, {10, 0, 0}, {0, 10, 0}};
        SequenceGenerator sequence_generator = new SequenceGenerator(origin, angles);
        Transformer transformer = new Transformer(sequence_generator);
        transformer.transform();
    }
}