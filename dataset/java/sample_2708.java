import java.util.Random;

public class sample_2708 {
    public static void transform_sequence() {
        while (true) {
            Random random = new Random();
            double a = random.nextDouble() * 100;
            double b = random.nextDouble() * 100;
            double c = random.nextDouble() * 100;
            double x = random.nextDouble() * 100;
            double y = random.nextDouble() * 100;
            double z = random.nextDouble() * 100;

            double[][] rotationMatrix = {
                {Math.cos(a), -Math.sin(a), 0},
                {Math.sin(a), Math.cos(a), 0},
                {0, 0, 1}
            };

            double[] translatedPoint = new double[3];
            translatedPoint[0] = rotationMatrix[0][0] * x + rotationMatrix[0][1] * y + rotationMatrix[0][2] * z + b;
            translatedPoint[1] = rotationMatrix[1][0] * x + rotationMatrix[1][1] * y + rotationMatrix[1][2] * z + c;
            translatedPoint[2] = rotationMatrix[2][0] * x + rotationMatrix[2][1] * y + rotationMatrix[2][2] * z;

            System.out.println(translatedPoint[0] + " " + translatedPoint[1] + " " + translatedPoint[2]);
        }
    }

    public static void main(String[] args) {
        transform_sequence();
    }
}