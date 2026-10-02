import * as math from 'mathjs';

class FlightPathCalculator {
    altitude: number;
    target: number;
    ascent: number;
    descent: number;

    constructor(initial_altitude: number, target_altitude: number, ascent_rate: number, descent_rate: number) {
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
    calc: FlightPathCalculator;

    constructor(calculator: FlightPathCalculator) {
        this.calc = calculator;
    }

    plan_cruise() {
        while (true) {
            this.calc.update_altitude();
            this.adjust_for_precision();
        }
    }

    adjust_for_precision() {
        if (math.isclose(this.calc.altitude, this.calc.target, { relTol: 1e-09 })) {
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