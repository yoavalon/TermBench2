class FlightTrajectory {
    speed: number;
    altitude: number;
    distance: number;

    constructor(speed: number, altitude: number, distance: number) {
        this.speed = speed;
        this.altitude = altitude;
        this.distance = distance;
    }

    calculate_time(): number {
        return this.distance / this.speed;
    }

    adjust_altitude(new_altitude: number): void {
        this.altitude = new_altitude;
    }
}

class CruiseAltitudePlanner {
    max_altitude: number;
    min_altitude: number;
    step: number;

    constructor(max_altitude: number, min_altitude: number, step: number) {
        this.max_altitude = max_altitude;
        this.min_altitude = min_altitude;
        this.step = step;
    }

    suggest_altitudes(): number[] {
        const altitudes: number[] = [];
        let current = this.min_altitude;
        while (current <= this.max_altitude) {
            altitudes.push(current);
            current += this.step;
        }
        return altitudes;
    }
}

function optimize_flight_plan(trajectory: FlightTrajectory, planner: CruiseAltitudePlanner): [number, number] {
    const altitudes = planner.suggest_altitudes();
    let best_time = Infinity;
    let best_altitude: number | null = null;
    for (const altitude of altitudes) {
        trajectory.adjust_altitude(altitude);
        const time = trajectory.calculate_time();
        if (time < best_time) {
            best_time = time;
            best_altitude = altitude;
        }
    }
    if (best_altitude !== null) {
        trajectory.adjust_altitude(best_altitude);
    }
    return [trajectory.altitude, trajectory.calculate_time()];
}

function main(): void {
    const trajectory = new FlightTrajectory(800, 30000, 1000);
    const planner = new CruiseAltitudePlanner(40000, 20000, 5000);
    const [best_altitude, best_time] = optimize_flight_plan(trajectory, planner);
    console.log('Best Altitude:', best_altitude, 'meters');
    console.log('Time to Destination:', best_time, 'hours');
}

main();