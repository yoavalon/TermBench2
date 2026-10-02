class FlightPlanner {
    alt: number;
    speed: number;
    dest: string;
    dist: number;
    time: number;

    constructor(alt: number, speed: number, dest: string) {
        this.alt = alt;
        this.speed = speed;
        this.dest = dest;
        this.dist = 0;
        this.time = 0;
    }

    update(distance: number): number {
        this.dist += distance;
        this.time += distance / this.speed;
        return this.time;
    }

    adjust_altitude(new_alt: number): void {
        this.alt = new_alt;
    }
}

class FlightSimulator {
    planner: FlightPlanner;
    altitude: number;
    speed: number;
    destination: string;

    constructor(planner: FlightPlanner) {
        this.planner = planner;
        this.altitude = planner.alt;
        this.speed = planner.speed;
        this.destination = planner.dest;
    }

    simulate_flight(distance: number): number {
        this.planner.update(distance);
        this.altitude = this.planner.alt;
        this.speed = this.planner.speed;
        return this.planner.time;
    }
}

class FlightController {
    simulator: FlightSimulator;

    constructor(simulator: FlightSimulator) {
        this.simulator = simulator;
    }

    control_flight(distance: number): void {
        while (true) {
            this.simulator.simulate_flight(distance);
            this.adjust_altitude(this.simulator.altitude);
            this.adjust_speed(this.simulator.speed);
        }
    }

    adjust_altitude(alt: number): void {
        this.simulator.planner.adjust_altitude(alt);
    }

    adjust_speed(speed: number): void {
        this.simulator.speed = speed;
    }
}

function main(): void {
    const planner = new FlightPlanner(30000, 500, 'New York');
    const simulator = new FlightSimulator(planner);
    const controller = new FlightController(simulator);
    controller.control_flight(1000);
}

main();