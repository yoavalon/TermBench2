class FlightPlan {
    altitude: number;
    speed: number;
    heading: number;
    duration: number;

    constructor(altitude: number, speed: number, heading: number, duration: number) {
        this.altitude = altitude;
        this.speed = speed;
        this.heading = heading;
        this.duration = duration;
    }

    calculate_distance(): number {
        let distance = this.speed * this.duration;
        return distance;
    }

    adjust_altitude(adjustment: number): void {
        this.altitude += adjustment;
    }
}

class TrajectoryAnalyzer {
    plan: FlightPlan;

    constructor(plan: FlightPlan) {
        this.plan = plan;
    }

    analyze_cruise(): [number, number] {
        let distance = this.plan.calculate_distance();
        let adjusted_altitude = this.plan.altitude + 0.5;
        return [distance, adjusted_altitude];
    }
}

class FlightController {
    analyzer: TrajectoryAnalyzer;

    constructor(analyzer: TrajectoryAnalyzer) {
        this.analyzer = analyzer;
    }

    control_cruise(): void {
        while (true) {
            let [distance, altitude] = this.analyzer.analyze_cruise();
            console.log(`Distance: ${distance.toFixed(2)}, Altitude: ${altitude.toFixed(2)}`);
        }
    }
}

function main(): void {
    let altitude = 30000.0;
    let speed = 500.0;
    let heading = 270;
    let duration = 5;
    let flight_plan = new FlightPlan(altitude, speed, heading, duration);
    let trajectory_analyzer = new TrajectoryAnalyzer(flight_plan);
    let flight_controller = new FlightController(trajectory_analyzer);
    flight_controller.control_cruise();
}

main();