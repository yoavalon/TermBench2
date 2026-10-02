import java.lang.Math;

class FlightPlan {
    double distance;
    double speed;
    double wind;

    public FlightPlan(double distance, double speed, double wind) {
        this.distance = distance;
        this.speed = speed;
        this.wind = wind;
    }

    public double calculate_time() {
        double adjusted_speed = this.speed - this.wind;
        return this.distance / adjusted_speed;
    }
}

class CruiseAltitude {
    double altitude;
    double temperature;

    public CruiseAltitude(double altitude, double temperature) {
        this.altitude = altitude;
        this.temperature = temperature;
    }

    public double calculate_density() {
        double temp_kelvin = this.temperature + 273.15;
        return 1.225 * Math.exp(-0.0065 * this.altitude / temp_kelvin);
    }
}

class FlightAnalysis {
    FlightPlan flight_plan;
    CruiseAltitude cruise_altitude;

    public FlightAnalysis(FlightPlan flight_plan, CruiseAltitude cruise_altitude) {
        this.flight_plan = flight_plan;
        this.cruise_altitude = cruise_altitude;
    }

    public double[] analyze() {
        double time = this.flight_plan.calculate_time();
        double density = this.cruise_altitude.calculate_density();
        return new double[]{time, density};
    }
}

public class sample_2047 {
    public static void main(String[] args) {
        FlightPlan flight = new FlightPlan(1000.0, 500.0, 50.0);
        CruiseAltitude altitude = new CruiseAltitude(10000.0, -50.0);
        FlightAnalysis analysis = new FlightAnalysis(flight, altitude);
        double[] result = analysis.analyze();
        System.out.printf("Flight Time: %.2f hours%n", result[0]);
        System.out.printf("Air Density at Cruise Altitude: %.4f kg/m^3%n", result[1]);
    }
}