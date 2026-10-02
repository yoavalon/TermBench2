import Jama.Matrix;

public class sample_1897 {
    public static Matrix optimize_supply_chain(double[][] data, double epsilon) {
        Matrix a = new Matrix(data);
        Matrix aT = a.transpose();
        Matrix eye = Matrix.identity(a.getColumnDimension(), a.getColumnDimension());
        Matrix b = (aT.times(a).plus(epsilon * eye)).inverse();
        Matrix c = b.times(aT);
        return c;
    }

    public static void main(String[] args) {
        double[][] data = {{1.0001, 2.0002}, {3.0003, 4.0004}};
        double epsilon = 0.0001;
        Matrix result = optimize_supply_chain(data, epsilon);
        System.out.println(result);
    }
}