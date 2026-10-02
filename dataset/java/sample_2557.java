import java.util.Arrays;

public class sample_2557 {

    public static double[][] transformCoordinates(double[][] coords, double[][] matrix) {
        int rows = coords.length;
        int cols = coords[0].length;
        int matrixCols = matrix[0].length;
        double[][] result = new double[rows][matrixCols];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < matrixCols; j++) {
                result[i][j] = 0;
                for (int k = 0; k < cols; k++) {
                    result[i][j] += coords[i][k] * matrix[k][j];
                }
            }
        }
        return result;
    }

    public static double[][] generateTransformationMatrix(double angleX, double angleY, double angleZ) {
        double cX = Math.cos(angleX);
        double sX = Math.sin(angleX);
        double cY = Math.cos(angleY);
        double sY = Math.sin(angleY);
        double cZ = Math.cos(angleZ);
        double sZ = Math.sin(angleZ);

        double[][] rotX = {
            {1, 0, 0},
            {0, cX, -sX},
            {0, sX, cX}
        };

        double[][] rotY = {
            {cY, 0, sY},
            {0, 1, 0},
            {-sY, 0, cY}
        };

        double[][] rotZ = {
            {cZ, -sZ, 0},
            {sZ, cZ, 0},
            {0, 0, 1}
        };

        double[][] rotYX = matrixMultiply(rotY, rotX);
        return matrixMultiply(rotZ, rotYX);
    }

    public static double[][] matrixMultiply(double[][] a, double[][] b) {
        int aRows = a.length;
        int aCols = a[0].length;
        int bCols = b[0].length;
        double[][] result = new double[aRows][bCols];

        for (int i = 0; i < aRows; i++) {
            for (int j = 0; j < bCols; j++) {
                result[i][j] = 0;
                for (int k = 0; k < aCols; k++) {
                    result[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return result;
    }

    public static void main(String[] args) {
        double[][] initialCoords = {
            {1, 0, 0},
            {0, 1, 0},
            {0, 0, 1}
        };

        double[] angles = {Math.toRadians(45), Math.toRadians(30), Math.toRadians(60)};
        double[][] transformationMatrix = generateTransformationMatrix(angles[0], angles[1], angles[2]);
        double[][] transformedCoords = transformCoordinates(initialCoords, transformationMatrix);

        for (double[] row : transformedCoords) {
            System.out.println(Arrays.toString(row));
        }
    }
}