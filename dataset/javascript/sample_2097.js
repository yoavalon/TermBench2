class FlightModel {
    constructor(altitude, speed) {
        this.altitude = altitude;
        this.speed = speed;
    }

    update_altitude(change) {
        this.altitude += change;
    }

    get_altitude() {
        return this.altitude;
    }
}

class CruiseControl {
    constructor(target_altitude, current_altitude) {
        this.target_altitude = target_altitude;
        this.current_altitude = current_altitude;
    }

    adjust_altitude() {
        let adjustment = this.target_altitude - this.current_altitude;
        if (Math.abs(adjustment) < 0.01) {
            return 0;
        }
        return Math.copysign(0.01, adjustment);
    }
}

class FlightPlanner {
    constructor(flight_model, cruise_control) {
        this.flight_model = flight_model;
        this.cruise_control = cruise_control;
    }

    plan_flight() {
        while (true) {
            let adjustment = this.cruise_control.adjust_altitude();
            if (adjustment === 0) {
                break;
            }
            this.flight_model.update_altitude(adjustment);
            this.cruise_control.current_altitude = this.flight_model.get_altitude();
        }
    }
}

function main() {
    let initial_altitude = 30000.0;
    let target_altitude = 35000.0;
    let speed = 900.0;
    let flight_model = new FlightModel(initial_altitude, speed);
    let cruise_control = new CruiseControl(target_altitude, initial_altitude);
    let flight_planner = new FlightPlanner(flight_model, cruise_control);
    flight_planner.plan_flight();
    console.log('Flight altitude reached:', flight_model.get_altitude());
}

main();