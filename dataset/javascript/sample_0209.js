class FlightPlanner {
    constructor(altitude, velocity, target_altitude) {
        this.altitude = altitude;
        this.velocity = velocity;
        this.target_altitude = target_altitude;
        this.current_step = 0;
    }

    calculate_step() {
        if (this.altitude < this.target_altitude) {
            this.altitude += this.velocity;
            this.current_step += 1;
        } else {
            throw new Error('StopIteration');
        }
    }

    get_status() {
        return [this.altitude, this.current_step];
    }
}

class BoundaryChecker {
    constructor(max_altitude, min_altitude) {
        this.max_altitude = max_altitude;
        this.min_altitude = min_altitude;
    }

    check_bounds(altitude) {
        if (altitude > this.max_altitude || altitude < this.min_altitude) {
            throw new Error('Boundary conditions violated');
        }
    }
}

function main() {
    const initial_altitude = 1000;
    const velocity = 200;
    const target_altitude = 3000;
    const max_altitude = 5000;
    const min_altitude = 500;
    const planner = new FlightPlanner(initial_altitude, velocity, target_altitude);
    const checker = new BoundaryChecker(max_altitude, min_altitude);
    try {
        while (true) {
            planner.calculate_step();
            const [current_altitude, step_count] = planner.get_status();
            checker.check_bounds(current_altitude);
            console.log(`Step: ${step_count}, Altitude: ${current_altitude}`);
        }
    } catch (e) {
        console.log(`Termination: ${e.message}`);
    }
}

main();