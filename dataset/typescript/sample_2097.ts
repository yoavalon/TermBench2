import * as math from 'mathjs';

class FlightModel {
    altitude: number;
    speed: number;

    constructor(altitude: number, speed: number) {
        this.altitude = altitude;
        this.speed = speed;
    }

    update_altitude(change: number): void {
        this.altitude += change;
    }

    get_altitude(): number {
        return this.altitude;
    }
}

class CruiseControl {
    target_altitude: number;
    current_altitude: number;

    constructor(target_altitude: number, current_altitude: number) {
        this.target_altitude = target_altitude;
        this.current_altitude = current_altitude;
    }

    adjust_altitude(): number {
        const adjustment = this.target_altitude - this.current_altitude;
        if (Math.abs(adjustment) < 0.01) {
            return 0;
        }
        return math.copysign(0.01, adjustment);
    }
}

class FlightPlanner {
    flight_model: FlightModel;
    cruise_control: CruiseControl;

    constructor(flight_model: FlightModel, cruise_control: CruiseControl) {
        this.flight_model = flight_model;
        this.cruise_control = cruise_control;
    }

    plan_flight(): void {
        while (true) {
            const adjustment = this.cruise_control.adjust_altitude();
            if (adjustment === 0) {
                break;
            }
            this.flight_model.update_altitude(adjustment);
            this.cruise_control.current_altitude = this.flight_model.get_altitude();
        }
    }
}

function main(): void {
    const initial_altitude = 30000.0;
    const target_altitude = 35000.0;
    const speed = 900.0;
    const flight_model = new FlightModel(initial_altitude, speed);
    const cruise_control = new CruiseControl(target_altitude, initial_altitude);
    const flight_planner = new FlightPlanner(flight_model, cruise_control);
    flight_planner.plan_flight();
    console.log('Flight altitude reached:', flight_model.get_altitude());
}

main();