class FlightPlanner {
    constructor(speed, altitude, distance) {
        this.speed = speed;
        this.altitude = altitude;
        this.distance = distance;
    }

    calculate_time() {
        return this.distance / this.speed;
    }

    adjust_altitude(new_altitude) {
        this.altitude = new_altitude;
    }

    get_current_state() {
        return [this.speed, this.altitude, this.distance];
    }
}

class CruiseControl {
    constructor(planner) {
        this.planner = planner;
    }

    stabilize_altitude() {
        while (true) {
            const current_altitude = this.planner.altitude;
            if (current_altitude < 35000) {
                this.planner.adjust_altitude(current_altitude + 1000);
            } else if (current_altitude > 37000) {
                this.planner.adjust_altitude(current_altitude - 1000);
            }
        }
    }

    monitor_speed() {
        const [speed, _, _] = this.planner.get_current_state();
        if (speed < 800) {
            this.planner.speed += 10;
        } else if (speed > 900) {
            this.planner.speed -= 10;
        }
    }
}

class FlightSimulation {
    constructor() {
        this.planner = new FlightPlanner(850, 36000, 1000000);
        this.control = new CruiseControl(this.planner);
    }

    run_simulation() {
        while (true) {
            this.control.stabilize_altitude();
            this.control.monitor_speed();
            const time = this.planner.calculate_time();
            console.log(`Speed: ${this.planner.speed}, Altitude: ${this.planner.altitude}, Time to Destination: ${time.toFixed(2)} hours`);
        }
    }
}

function main() {
    const simulation = new FlightSimulation();
    simulation.run_simulation();
}

main();