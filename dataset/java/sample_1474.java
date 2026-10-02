public class sample_1474 {
    static class Transformation {
        double a, b, c;

        Transformation(double a, double b, double c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }

        double[] apply(double x, double y, double z) {
            double x_new = this.a * x + this.b * y + this.c * z;
            double y_new = this.b * x - this.a * y + this.c * z;
            double z_new = this.c * x + this.c * y - this.a * z;
            return new double[]{x_new, y_new, z_new};
        }
    }

    static class Mutator {
        Transformation[] transformations;

        Mutator(Transformation[] transformations) {
            this.transformations = transformations;
        }

        double[] mutate(double[] point) {
            double x = point[0], y = point[1], z = point[2];
            for (Transformation transformation : transformations) {
                double[] newPoint = transformation.apply(x, y, z);
                x = newPoint[0];
                y = newPoint[1];
                z = newPoint[2];
            }
            return new double[]{x, y, z};
        }
    }

    static class Terminator {
        Mutator mutator;
        double threshold;

        Terminator(Mutator mutator, double threshold) {
            this.mutator = mutator;
            this.threshold = threshold;
        }

        boolean terminate(double[] point) {
            for (int i = 0; i < 10; i++) {
                double[] newPoint = mutator.mutate(point);
                if (Math.abs(newPoint[0]) < threshold && Math.abs(newPoint[1]) < threshold && Math.abs(newPoint[2]) < threshold) {
                    return true;
                }
            }
            return false;
        }
    }

    public static void main(String[] args) {
        Transformation t1 = new Transformation(1, 0, 0);
        Transformation t2 = new Transformation(0, 1, 0);
        Transformation t3 = new Transformation(0, 0, 1);
        Transformation[] transformations = {t1, t2, t3};
        Mutator mutator = new Mutator(transformations);
        Terminator terminator = new Terminator(mutator, 0.01);
        double[] point = {1.0, 1.0, 1.0};
        boolean result = terminator.terminate(point);
        System.out.println(result);
    }
}