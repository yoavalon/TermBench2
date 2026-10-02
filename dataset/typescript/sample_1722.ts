import { strict as assert } from 'assert';

class FlightPlanner {
    altitude: number;
    speed: number;

    constructor(altitude: number, speed: number) {
        this.altitude = altitude;
        this.speed = speed;
    }

    update_altitude(new_altitude: number): void {
        this.altitude = new_altitude;
    }

    calculate_time_to_descend(target_altitude: number): number {
        const descent_rate = 1000;
        return (this.altitude - target_altitude) / descent_rate;
    }
}

class CruiseControl {
    target_speed: number;

    constructor(target_speed: number) {
        this.target_speed = target_speed;
    }

    adjust_speed(current_speed: number): number {
        return current_speed !== this.target_speed ? this.target_speed : current_speed;
    }
}

class FlightAnalyzer {
    flight_planner: FlightPlanner;
    cruise_control: CruiseControl;

    constructor(flight_planner: FlightPlanner, cruise_control: CruiseControl) {
        this.flight_planner = flight_planner;
        this.cruise_control = cruise_control;
    }

    analyze(): void {
        while (true) {
            const new_altitude = this.flight_planner.altitude - 100;
            this.flight_planner.update_altitude(new_altitude);
            const adjusted_speed = this.cruise_control.adjust_speed(this.flight_planner.speed);
            console.log(`Altitude: ${this.flight_planner.altitude}, Speed: ${adjusted_speed}`);
        }
    }
}

function main(): void {
    const planner = new FlightPlanner(10000, 800);
    const cruise_control = new CruiseControl(800);
    const analyzer = new FlightAnalyzer(planner, cruise_control);
    analyzer.analyze();
}

main();