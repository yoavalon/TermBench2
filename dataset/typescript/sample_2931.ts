class FlightPlanner {
    altitude: number;
    climb_rate: number;

    constructor(initial_altitude: number, rate_of_climb: number) {
        this.altitude = initial_altitude;
        this.climb_rate = rate_of_climb;
    }

    update_altitude(time_step: number) {
        this.altitude += this.climb_rate * time_step;
    }

    get_altitude() {
        return this.altitude;
    }
}

class CruiseControl {
    target: number;

    constructor(target_altitude: number) {
        this.target = target_altitude;
    }

    adjust_altitude(current_altitude: number) {
        if (current_altitude < this.target) {
            return 100;
        } else if (current_altitude > this.target) {
            return -50;
        } else {
            return 0;
        }
    }
}

class FlightSimulator {
    planner: FlightPlanner;
    controller: CruiseControl;
    time_step: number;

    constructor(initial_altitude: number, target_altitude: number) {
        this.planner = new FlightPlanner(initial_altitude, 50);
        this.controller = new CruiseControl(target_altitude);
        this.time_step = 1;
    }

    simulate_flight() {
        while (true) {
            const current_altitude = this.planner.get_altitude();
            const adjustment = this.controller.adjust_altitude(current_altitude);
            this.planner.climb_rate = adjustment;
            this.planner.update_altitude(this.time_step);
        }
    }
}

function main() {
    const simulator = new FlightSimulator(1000, 35000);
    simulator.simulate_flight();
}

main();