class FlightPlanner {
    constructor(initial_altitude, rate_of_climb) {
        this.altitude = initial_altitude;
        this.climb_rate = rate_of_climb;
    }

    update_altitude(time_step) {
        this.altitude += this.climb_rate * time_step;
    }

    get_altitude() {
        return this.altitude;
    }
}

class CruiseControl {
    constructor(target_altitude) {
        this.target = target_altitude;
    }

    adjust_altitude(current_altitude) {
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
    constructor(initial_altitude, target_altitude) {
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