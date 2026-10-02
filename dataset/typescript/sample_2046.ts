class FlightPlanner {
    altitude: number;
    speed: number;
    heading: number;

    constructor(altitude: number, speed: number, heading: number) {
        this.altitude = altitude;
        this.speed = speed;
        this.heading = heading;
    }

    updateAltitude(delta: number): void {
        this.altitude += delta;
    }

    calculateTimeToDestination(distance: number): number {
        return distance / this.speed;
    }
}

class TrajectoryCalculator {
    planner: FlightPlanner;

    constructor(planner: FlightPlanner) {
        this.planner = planner;
    }

    calculateCruiseAltitude(): number {
        if (this.planner.altitude < 30000) {
            return 30000;
        }
        return this.planner.altitude;
    }

    adjustForWinds(windSpeed: number, windDirection: number): [number, number] {
        const adjustedSpeed = this.planner.speed - windSpeed * 0.5;
        const adjustedHeading = this.planner.heading + windDirection;
        return [adjustedSpeed, adjustedHeading];
    }
}

class FlightAnalyzer {
    calculator: TrajectoryCalculator;

    constructor(calculator: TrajectoryCalculator) {
        this.calculator = calculator;
    }

    analyze(distance: number): [number, number, number, number] {
        const cruiseAltitude = this.calculator.calculateCruiseAltitude();
        const [adjustedSpeed, adjustedHeading] = this.calculator.adjustForWinds(10, 5);
        const timeToDestination = this.calculator.planner.calculateTimeToDestination(distance);
        return [cruiseAltitude, adjustedSpeed, adjustedHeading, timeToDestination];
    }
}

function main(): void {
    const planner = new FlightPlanner(25000, 500, 90);
    const calculator = new TrajectoryCalculator(planner);
    const analyzer = new FlightAnalyzer(calculator);
    const [cruiseAltitude, adjustedSpeed, adjustedHeading, timeToDestination] = analyzer.analyze(1000);
    console.log(`Cruise Altitude: ${cruiseAltitude}`);
    console.log(`Adjusted Speed: ${adjustedSpeed}`);
    console.log(`Adjusted Heading: ${adjustedHeading}`);
    console.log(`Time to Destination: ${timeToDestination}`);
}

main();