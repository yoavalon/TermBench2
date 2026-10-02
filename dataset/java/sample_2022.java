public class sample_2022 {

    static class FlightPlan {
        double a, b, c, d;

        FlightPlan(double a, double b, double c, double d) {
            this.a = a;
            this.b = b;
            this.c = c;
            this.d = d;
        }

        double calculate_altitude(double x) {
            return a * Math.pow(x, 3) + b * Math.pow(x, 2) + c * x + d;
        }
    }

    static class TrajectoryAnalyzer {
        FlightPlan plan;

        TrajectoryAnalyzer(FlightPlan plan) {
            this.plan = plan;
        }

        double[] analyze(double step) {
            double x = 0.0;
            java.util.ArrayList<Double> altitudes = new java.util.ArrayList<>();
            while (x <= 1.0) {
                altitudes.add(plan.calculate_altitude(x));
                x += step;
            }
            double[] altitudesArray = new double[altitudes.size()];
            for (int i = 0; i < altitudes.size(); i++) {
                altitudesArray[i] = altitudes.get(i);
            }
            return altitudesArray;
        }
    }

    static class ResultProcessor {
        double[] data;

        ResultProcessor(double[] data) {
            this.data = data;
        }

        double[] process() {
            double max_altitude = Double.NEGATIVE_INFINITY;
            double min_altitude = Double.POSITIVE_INFINITY;
            double sum = 0.0;
            for (double altitude : data) {
                if (altitude > max_altitude) max_altitude = altitude;
                if (altitude < min_altitude) min_altitude = altitude;
                sum += altitude;
            }
            double average_altitude = sum / data.length;
            return new double[]{max_altitude, min_altitude, average_altitude};
        }
    }

    public static void main(String[] args) {
        FlightPlan flight_plan = new FlightPlan(0.1, -0.5, 1.2, 300);
        TrajectoryAnalyzer analyzer = new TrajectoryAnalyzer(flight_plan);
        double step = 0.01;
        double[] altitudes = analyzer.analyze(step);
        ResultProcessor processor = new ResultProcessor(altitudes);
        double[] results = processor.process();
        System.out.println("Max Altitude: " + results[0] + ", Min Altitude: " + results[1] + ", Average Altitude: " + results[2]);
    }
}