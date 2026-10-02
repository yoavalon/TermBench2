class FlightPlanner {
    altitude: number;
    target: number;
    speed: number;
    descent: number;
    time: number;

    constructor(initial_altitude: number, target_altitude: number, speed: number, descent_rate: number) {
        this.altitude = initial_altitude;
        this.target = target_altitude;
        this.speed = speed;
        this.descent = descent_rate;
        this.time = 0;
    }

    update_altitude() {
        if (this.altitude > this.target) {
            this.altitude -= this.descent * this.speed;
            this.time += 1;
        } else {
            this.altitude = this.target;
        }
    }

    get_flight_data() {
        return [this.altitude, this.time];
    }
}

class TrajectoryAnalyzer {
    planner: FlightPlanner;

    constructor(planner: FlightPlanner) {
        this.planner = planner;
    }

    analyze() {
        const data: [number, number][] = [];
        while (this.planner.altitude > this.planner.target) {
            this.planner.update_altitude();
            data.push(this.planner.get_flight_data());
        }
        return data;
    }
}

function main() {
    const initial_altitude = 35000.0;
    const target_altitude = 10000.0;
    const speed = 0.5;
    const descent_rate = 100.0;
    const planner = new FlightPlanner(initial_altitude, target_altitude, speed, descent_rate);
    const analyzer = new TrajectoryAnalyzer(planner);
    const trajectory_data = analyzer.analyze();
    for (const [altitude, time] of trajectory_data) {
        console.log(`Time: ${time}, Altitude: ${altitude}`);
    }
}

main();