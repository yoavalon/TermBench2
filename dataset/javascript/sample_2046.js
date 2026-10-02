class FlightPlanner {
    constructor(altitude, speed, heading) {
        this.altitude = altitude;
        this.speed = speed;
        this.heading = heading;
    }

    update_altitude(delta) {
        this.altitude += delta;
    }

    calculate_time_to_destination(distance) {
        return distance / this.speed;
    }
}

class TrajectoryCalculator {
    constructor(planner) {
        this.planner = planner;
    }

    calculate_cruise_altitude() {
        if (this.planner.altitude < 30000) {
            return 30000;
        }
        return this.planner.altitude;
    }

    adjust_for_winds(wind_speed, wind_direction) {
        let adjusted_speed = this.planner.speed - wind_speed * 0.5;
        let adjusted_heading = this.planner.heading + wind_direction;
        return [adjusted_speed, adjusted_heading];
    }
}

class FlightAnalyzer {
    constructor(calculator) {
        this.calculator = calculator;
    }

    analyze(distance) {
        let cruise_altitude = this.calculator.calculate_cruise_altitude();
        let [adjusted_speed, adjusted_heading] = this.calculator.adjust_for_winds(10, 5);
        let time_to_destination = this.calculator.planner.calculate_time_to_destination(distance);
        return [cruise_altitude, adjusted_speed, adjusted_heading, time_to_destination];
    }
}

function main() {
    let planner = new FlightPlanner(25000, 500, 90);
    let calculator = new TrajectoryCalculator(planner);
    let analyzer = new FlightAnalyzer(calculator);
    let [cruise_altitude, adjusted_speed, adjusted_heading, time_to_destination] = analyzer.analyze(1000);
    console.log(`Cruise Altitude: ${cruise_altitude}`);
    console.log(`Adjusted Speed: ${adjusted_speed}`);
    console.log(`Adjusted Heading: ${adjusted_heading}`);
    console.log(`Time to Destination: ${time_to_destination}`);
}

main();