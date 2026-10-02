class FlightPlanner {
    constructor(initial_altitude, target_altitude, rate_of_climb, max_altitude) {
        this.current_altitude = initial_altitude;
        this.target_altitude = target_altitude;
        this.rate_of_climb = rate_of_climb;
        this.max_altitude = max_altitude;
    }

    climb() {
        if (this.current_altitude < this.target_altitude) {
            this.current_altitude += this.rate_of_climb;
            if (this.current_altitude > this.max_altitude) {
                this.current_altitude = this.max_altitude;
            }
        }
    }

    stabilize() {
        if (this.current_altitude === this.target_altitude) {
            return true;
        }
        return false;
    }

    plan_flight() {
        while (!this.stabilize()) {
            this.climb();
        }
        return this.current_altitude;
    }
}

class FlightData {
    constructor(altitudes) {
        this.altitudes = altitudes;
    }

    update_altitude(new_altitude) {
        this.altitudes.push(new_altitude);
    }

    get_altitudes() {
        return this.altitudes;
    }
}

class FlightController {
    constructor(planner, data) {
        this.planner = planner;
        this.data = data;
    }

    execute_flight() {
        const final_altitude = this.planner.plan_flight();
        this.data.update_altitude(final_altitude);
        return this.data.get_altitudes();
    }
}

function main() {
    const initial_altitude = 5000;
    const target_altitude = 35000;
    const rate_of_climb = 1000;
    const max_altitude = 40000;
    const planner = new FlightPlanner(initial_altitude, target_altitude, rate_of_climb, max_altitude);
    const data = new FlightData([initial_altitude]);
    const controller = new FlightController(planner, data);
    const altitudes = controller.execute_flight();
    console.log(altitudes);
}

main();