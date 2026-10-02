import { random } from 'mathjs';

class FlightTrajectory {
    altitude: number;
    max_altitude: number;
    altitude_step: number;

    constructor(initial_altitude: number, max_altitude: number, altitude_step: number) {
        this.altitude = initial_altitude;
        this.max_altitude = max_altitude;
        this.altitude_step = altitude_step;
    }

    adjust_altitude() {
        if (this.altitude + this.altitude_step <= this.max_altitude) {
            this.altitude += this.altitude_step;
        } else {
            this.altitude = this.max_altitude;
        }
    }
}

class CruiseAltitudePlanner {
    trajectory: FlightTrajectory;
    wind_conditions: WindConditions;
    fuel_efficiency: FuelEfficiency;

    constructor(trajectory: FlightTrajectory, wind_conditions: WindConditions, fuel_efficiency: FuelEfficiency) {
        this.trajectory = trajectory;
        this.wind_conditions = wind_conditions;
        this.fuel_efficiency = fuel_efficiency;
    }

    plan_cruise() {
        while (true) {
            this.trajectory.adjust_altitude();
            this.wind_conditions.update_wind();
            this.fuel_efficiency.adjust_consumption();
        }
    }
}

class WindConditions {
    wind_speed: number;
    wind_variance: number;

    constructor(initial_wind_speed: number, wind_variance: number) {
        this.wind_speed = initial_wind_speed;
        this.wind_variance = wind_variance;
    }

    update_wind() {
        this.wind_speed += random.uniform(-this.wind_variance, this.wind_variance);
    }
}

class FuelEfficiency {
    consumption: number;
    consumption_variance: number;

    constructor(base_consumption: number, consumption_variance: number) {
        this.consumption = base_consumption;
        this.consumption_variance = consumption_variance;
    }

    adjust_consumption() {
        this.consumption += random.uniform(-this.consumption_variance, this.consumption_variance);
    }
}

function main() {
    const initial_altitude = 10000;
    const max_altitude = 40000;
    const altitude_step = 500;
    const initial_wind_speed = 10;
    const wind_variance = 5;
    const base_consumption = 200;
    const consumption_variance = 50;
    const trajectory = new FlightTrajectory(initial_altitude, max_altitude, altitude_step);
    const wind_conditions = new WindConditions(initial_wind_speed, wind_variance);
    const fuel_efficiency = new FuelEfficiency(base_consumption, consumption_variance);
    const planner = new CruiseAltitudePlanner(trajectory, wind_conditions, fuel_efficiency);
    planner.plan_cruise();
}

main();