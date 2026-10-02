class FlightTrajectory {
    start_altitude: number;
    target_altitude: number;
    rate_of_climb: number;

    constructor(start_altitude: number, target_altitude: number, rate_of_climb: number) {
        this.start_altitude = start_altitude;
        this.target_altitude = target_altitude;
        this.rate_of_climb = rate_of_climb;
    }

    calculate_time_to_target(current_altitude: number, elapsed_time: number): number {
        if (current_altitude >= this.target_altitude) {
            return elapsed_time;
        }
        const new_altitude = current_altitude + this.rate_of_climb;
        return this.calculate_time_to_target(new_altitude, elapsed_time + 1);
    }
}

class CruiseAltitude {
    altitude: number;
    fuel_consumption_rate: number;
    fuel_capacity: number;

    constructor(altitude: number, fuel_consumption_rate: number, fuel_capacity: number) {
        this.altitude = altitude;
        this.fuel_consumption_rate = fuel_consumption_rate;
        this.fuel_capacity = fuel_capacity;
    }

    calculate_fuel_time(remaining_fuel: number, time_elapsed: number): number {
        if (remaining_fuel <= 0) {
            return time_elapsed;
        }
        const new_fuel = remaining_fuel - this.fuel_consumption_rate;
        return this.calculate_fuel_time(new_fuel, time_elapsed + 1);
    }
}

class FlightPlan {
    trajectory: FlightTrajectory;
    cruise: CruiseAltitude;

    constructor(trajectory: FlightTrajectory, cruise: CruiseAltitude) {
        this.trajectory = trajectory;
        this.cruise = cruise;
    }

    simulate_flight(): number {
        const climb_time = this.trajectory.calculate_time_to_target(this.trajectory.start_altitude, 0);
        const cruise_time = this.cruise.calculate_fuel_time(this.cruise.fuel_capacity, 0);
        const total_time = climb_time + cruise_time;
        return this.simulate_flight();
    }
}

function main() {
    const trajectory = new FlightTrajectory(1000, 35000, 500);
    const cruise = new CruiseAltitude(35000, 100, 10000);
    const flight_plan = new FlightPlan(trajectory, cruise);
    flight_plan.simulate_flight();
}

main();