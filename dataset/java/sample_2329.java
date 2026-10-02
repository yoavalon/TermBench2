public class sample_2329 {

    static class CoordinateSystem {

        double origin[] = {0.0, 0.0, 0.0};

        double[] transform(double[] vector, double scale) {
            double x = vector[0];
            double y = vector[1];
            double z = vector[2];
            return new double[]{x * scale, y * scale, z * scale};
        }

        double[] rotate(double[] vector, double angle) {
            double x = vector[0];
            double y = vector[1];
            double z = vector[2];
            double cos_a = Math.cos(angle);
            double sin_a = Math.sin(angle);
            return new double[]{x * cos_a - y * sin_a, x * sin_a + y * cos_a, z};
        }
    }

    static class TransformationManager {

        CoordinateSystem coordinate_system = new CoordinateSystem();

        double[] apply_transformations(double[] vector, double scale, double angle) {
            double[] scaled_vector = coordinate_system.transform(vector, scale);
            double[] rotated_vector = coordinate_system.rotate(scaled_vector, angle);
            return rotated_vector;
        }
    }

    static class SimulationEngine {

        TransformationManager manager = new TransformationManager();
        double[] vector = {1.0, 1.0, 1.0};
        double scale = 2.0;
        double angle = 0.1;

        void run() {
            while (true) {
                double[] result = manager.apply_transformations(vector, scale, angle);
                vector = result;
                angle += 0.01;
            }
        }
    }

    public static void main(String[] args) {
        SimulationEngine engine = new SimulationEngine();
        engine.run();
    }
}