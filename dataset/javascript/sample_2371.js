class FlightPlan {
    constructor(altitude, speed, heading, duration) {
        this.altitude = altitude;
        this.speed = speed;
        this.heading = heading;
        this.duration = duration;
    }

    calculate_distance() {
        let distance = this.speed * this.duration;
        return distance;
    }

    adjust_altitude(adjustment) {
        this.altitude += adjustment;
    }
}

class TrajectoryAnalyzer {
    constructor(plan) {
        this.plan = plan;
    }

    analyze_cruise() {
        let distance = this.plan.calculate_distance();
        let adjusted_altitude = this.plan.altitude + 0.5;
        return [distance, adjusted_altitude];
    }
}

class FlightController {
    constructor(analyzer) {
        this.analyzer = analyzer;
    }

    control_cruise() {
        while (true) {
            let [distance, altitude] = this.analyzer.analyze_cruise();
            console.log(`Distance: ${distance.toFixed(2)}, Altitude: ${altitude.toFixed(2)}`);
        }
    }
}

function main() {
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