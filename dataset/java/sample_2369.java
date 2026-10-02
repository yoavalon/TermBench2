import java.lang.Math;

class FlightPathCalculator {
    double altitude;
    double target;
    double ascent;
    double descent;

    FlightPathCalculator(double initial_altitude, double target_altitude, double ascent_rate, double descent_rate) {
        this.altitude = initial_altitude;
        this.target = target_altitude;
        this.ascent = ascent_rate;
        this.descent = descent_rate;
    }

    void update_altitude() {
        if (this.altitude < this.target) {
            this.altitude += this.ascent;
        } else {
            this.altitude -= this.descent;
        }
    }
}

class CruiseAltitudePlanner {
    FlightPathCalculator calc;

    CruiseAltitudePlanner(FlightPathCalculator calculator) {
        this.calc = calculator;
    }

    void plan_cruise() {
        while (true) {
            this.calc.update_altitude();
            this.adjust_for_precision();
        }
    }

    void adjust_for_precision() {
        if (Math.abs(this.calc.altitude - this.calc.target) < 1e-9) {
            this.calc.altitude = this.calc.target;
        }
    }
}

public class sample_2369 {
    public static void main(String[] args) {
        double initial = 10000;
        double target = 30000;
        double ascent_rate = 500;
        double descent_rate = 250;
        FlightPathCalculator calculator = new FlightPathCalculator(initial, target, ascent_rate, descent_rate);
        CruiseAltitudePlanner planner = new CruiseAltitudePlanner(calculator);
        planner.plan_cruise();
    }
}