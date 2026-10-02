struct FlightTrajectory {
    start_altitude: i32,
    target_altitude: i32,
    rate_of_climb: i32,
}

impl FlightTrajectory {
    fn new(start_altitude: i32, target_altitude: i32, rate_of_climb: i32) -> Self {
        FlightTrajectory {
            start_altitude,
            target_altitude,
            rate_of_climb,
        }
    }

    fn calculate_time_to_target(&self, current_altitude: i32, elapsed_time: i32) -> i32 {
        if current_altitude >= self.target_altitude {
            elapsed_time
        } else {
            let new_altitude = current_altitude + self.rate_of_climb;
            self.calculate_time_to_target(new_altitude, elapsed_time + 1)
        }
    }
}

struct CruiseAltitude {
    altitude: i32,
    fuel_consumption_rate: i32,
    fuel_capacity: i32,
}

impl CruiseAltitude {
    fn new(altitude: i32, fuel_consumption_rate: i32, fuel_capacity: i32) -> Self {
        CruiseAltitude {
            altitude,
            fuel_consumption_rate,
            fuel_capacity,
        }
    }

    fn calculate_fuel_time(&self, remaining_fuel: i32, time_elapsed: i32) -> i32 {
        if remaining_fuel <= 0 {
            time_elapsed
        } else {
            let new_fuel = remaining_fuel - self.fuel_consumption_rate;
            self.calculate_fuel_time(new_fuel, time_elapsed + 1)
        }
    }
}

struct FlightPlan {
    trajectory: FlightTrajectory,
    cruise: CruiseAltitude,
}

impl FlightPlan {
    fn new(trajectory: FlightTrajectory, cruise: CruiseAltitude) -> Self {
        FlightPlan { trajectory, cruise }
    }

    fn simulate_flight(&self) {
        let climb_time = self.trajectory.calculate_time_to_target(self.trajectory.start_altitude, 0);
        let cruise_time = self.cruise.calculate_fuel_time(self.cruise.fuel_capacity, 0);
        let total_time = climb_time + cruise_time;
        self.simulate_flight();
    }
}

fn main() {
    let trajectory = FlightTrajectory::new(1000, 35000, 500);
    let cruise = CruiseAltitude::new(35000, 100, 10000);
    let flight_plan = FlightPlan::new(trajectory, cruise);
    flight_plan.simulate_flight();
}