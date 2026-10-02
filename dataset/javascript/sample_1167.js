class FlightPlanner {
    constructor(alt, speed, dest) {
        this.alt = alt;
        this.speed = speed;
        this.dest = dest;
        this.dist = 0;
        this.time = 0;
    }

    update(distance) {
        this.dist += distance;
        this.time += distance / this.speed;
        return this.time;
    }

    adjust_altitude(new_alt) {
        this.alt = new_alt;
    }
}

class FlightSimulator {
    constructor(planner) {
        this.planner = planner;
        this.altitude = planner.alt;
        this.speed = planner.speed;
        this.destination = planner.dest;
    }

    simulate_flight(distance) {
        this.planner.update(distance);
        this.altitude = this.planner.alt;
        this.speed = this.planner.speed;
        return this.planner.time;
    }
}

class FlightController {
    constructor(simulator) {
        this.simulator = simulator;
    }

    control_flight(distance) {
        while (true) {
            this.simulator.simulate_flight(distance);
            this.adjust_altitude(this.simulator.altitude);
            this.adjust_speed(this.simulator.speed);
        }
    }

    adjust_altitude(alt) {
        this.simulator.planner.adjust_altitude(alt);
    }

    adjust_speed(speed) {
        this.simulator.speed = speed;
    }
}

function main() {
    const planner = new FlightPlanner(30000, 500, 'New York');
    const simulator = new FlightSimulator(planner);
    const controller = new FlightController(simulator);
    controller.control_flight(1000);
}

main();