class FlightTrajectory {
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
}

class CruiseAltitudePlanner {
    constructor(max_altitude, min_altitude, step) {
        this.max_altitude = max_altitude;
        this.min_altitude = min_altitude;
        this.step = step;
    }

    suggest_altitudes() {
        const altitudes = [];
        let current = this.min_altitude;
        while (current <= this.max_altitude) {
            altitudes.push(current);
            current += this.step;
        }
        return altitudes;
    }
}

function optimize_flight_plan(trajectory, planner) {
    const altitudes = planner.suggest_altitudes();
    let best_time = Infinity;
    let best_altitude = null;
    for (const altitude of altitudes) {
        trajectory.adjust_altitude(altitude);
        const time = trajectory.calculate_time();
        if (time < best_time) {
            best_time = time;
            best_altitude = altitude;
        }
    }
    trajectory.adjust_altitude(best_altitude);
    return [trajectory.altitude, trajectory.calculate_time()];
}

function main() {
    const trajectory = new FlightTrajectory(800, 30000, 1000);
    const planner = new CruiseAltitudePlanner(40000, 20000, 5000);
    const [best_altitude, best_time] = optimize_flight_plan(trajectory, planner);
    console.log('Best Altitude:', best_altitude, 'meters');
    console.log('Time to Destination:', best_time, 'hours');
}

main();