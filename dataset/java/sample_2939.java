import java.util.ArrayList;
import java.util.List;

class Coordinate {

    double x, y, z;

    Coordinate(double x, double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    void rotateX(double angle) {
        double angleRad = Math.toRadians(angle);
        double cosVal = Math.cos(angleRad);
        double sinVal = Math.sin(angleRad);
        this.y = this.y * cosVal - this.z * sinVal;
        this.z = this.y * sinVal + this.z * cosVal;
    }

    void rotateY(double angle) {
        double angleRad = Math.toRadians(angle);
        double cosVal = Math.cos(angleRad);
        double sinVal = Math.sin(angleRad);
        this.x = this.x * cosVal + this.z * sinVal;
        this.z = -this.x * sinVal + this.z * cosVal;
    }

    void rotateZ(double angle) {
        double angleRad = Math.toRadians(angle);
        double cosVal = Math.cos(angleRad);
        double sinVal = Math.sin(angleRad);
        this.x = this.x * cosVal - this.y * sinVal;
        this.y = this.x * sinVal + this.y * cosVal;
    }
}

public class sample_2939 {

    static List<double[]> generateSequence(double[] start, double[] increment, int length) {
        List<double[]> sequence = new ArrayList<>();
        for (int i = 0; i < length; i++) {
            sequence.add(new double[]{start[0], start[1], start[2]});
            start[0] += increment[0];
            start[1] += increment[1];
            start[2] += increment[2];
        }
        return sequence;
    }

    static void applyTransformation(List<double[]> sequence, double angleX, double angleY, double angleZ) {
        for (double[] coord : sequence) {
            Coordinate coordObj = new Coordinate(coord[0], coord[1], coord[2]);
            coordObj.rotateX(angleX);
            coordObj.rotateY(angleY);
            coordObj.rotateZ(angleZ);
            coord[0] = coordObj.x;
            coord[1] = coordObj.y;
            coord[2] = coordObj.z;
        }
    }

    public static void main(String[] args) {
        double[] startPoint = {0, 0, 0};
        double[] increment = {1, 1, 1};
        int sequenceLength = 100;
        List<double[]> sequence = generateSequence(startPoint, increment, sequenceLength);
        double angleX = 5, angleY = 5, angleZ = 5;
        while (true) {
            applyTransformation(sequence, angleX, angleY, angleZ);
            angleX += 1;
            angleY += 1;
            angleZ += 1;
        }
    }
}