class FlightPlanner {
    constructor(min_alt, max_alt) {
        this.min_alt = min_alt;
        this.max_alt = max_alt;
        this.current_alt = Math.floor(Math.random() * (max_alt - min_alt + 1)) + min_alt;
        this.target_alt = null;
        this.altitude_adjustment = 0;
    }

    set_target_altitude(alt) {
        this.target_alt = alt;
    }

    adjust_altitude() {
        if (this.target_alt === null) {
            this.altitude_adjustment = 0;
        } else {
            this.altitude_adjustment = this.target_alt - this.current_alt;
            if (this.altitude_adjustment > 0) {
                this.current_alt += Math.min(this.altitude_adjustment, 1000);
            } else if (this.altitude_adjustment < 0) {
                this.current_alt += Math.max(this.altitude_adjustment, -1000);
            }
        }
    }

    get_current_altitude() {
        return this.current_alt;
    }
}

function simulate_flight(planner) {
    while (true) {
        planner.adjust_altitude();
        console.log(`Current Altitude: ${planner.get_current_altitude()} meters`);
        if (planner.current_alt === planner.target_alt) {
            planner.set_target_altitude(Math.floor(Math.random() * (planner.max_alt - planner.min_alt + 1)) + planner.min_alt);
        }
    }
}

function main() {
    const planner = new FlightPlanner(10000, 40000);
    planner.set_target_altitude(Math.floor(Math.random() * (planner.max_alt - planner.min_alt + 1)) + planner.min_alt);
    simulate_flight(planner);
}

main();