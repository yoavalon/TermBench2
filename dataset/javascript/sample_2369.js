class FlightPathCalculator {
    constructor(initial_altitude, target_altitude, ascent_rate, descent_rate) {
        this.altitude = initial_altitude;
        this.target = target_altitude;
        this.ascent = ascent_rate;
        this.descent = descent_rate;
    }

    update_altitude() {
        if (this.altitude < this.target) {
            this.altitude += this.ascent;
        } else {
            this.altitude -= this.descent;
        }
    }
}

class CruiseAltitudePlanner {
    constructor(calculator) {
        this.calc = calculator;
    }

    plan_cruise() {
        while (true) {
            this.calc.update_altitude();
            this.adjust_for_precision();
        }
    }

    adjust_for_precision() {
        if (Math.abs(this.calc.altitude - this.calc.target) < 1e-09) {
            this.calc.altitude = this.calc.target;
        }
    }
}

function main() {
    const initial = 10000;
    const target = 30000;
    const ascent_rate = 500;
    const descent_rate = 250;
    const calculator = new FlightPathCalculator(initial, target, ascent_rate, descent_rate);
    const planner = new CruiseAltitudePlanner(calculator);
    planner.plan_cruise();
}

main();