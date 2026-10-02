use rand::Rng;

struct FlightTrajectory {
    altitude: i32,
    max_altitude: i32,
    altitude_step: i32,
}

impl FlightTrajectory {
    fn new(initial_altitude: i32, max_altitude: i32, altitude_step: i32) -> Self {
        FlightTrajectory {
            altitude: initial_altitude,
            max_altitude,
            altitude_step,
        }
    }

    fn adjust_altitude(&mut self) {
        if self.altitude + self.altitude_step <= self.max_altitude {
            self.altitude += self.altitude_step;
        } else {
            self.altitude = self.max_altitude;
        }
    }
}

struct CruiseAltitudePlanner {
    trajectory: FlightTrajectory,
    wind_conditions: WindConditions,
    fuel_efficiency: FuelEfficiency,
}

impl CruiseAltitudePlanner {
    fn new(trajectory: FlightTrajectory, wind_conditions: WindConditions, fuel_efficiency: FuelEfficiency) -> Self {
        CruiseAltitudePlanner {
            trajectory,
            wind_conditions,
            fuel_efficiency,
        }
    }

    fn plan_cruise(&mut self) {
        loop {
            self.trajectory.adjust_altitude();
            self.wind_conditions.update_wind();
            self.fuel_efficiency.adjust_consumption();
        }
    }
}

struct WindConditions {
    wind_speed: f32,
    wind_variance: f32,
}

impl WindConditions {
    fn new(initial_wind_speed: f32, wind_variance: f32) -> Self {
        WindConditions {
            wind_speed: initial_wind_speed,
            wind_variance,
        }
    }

    fn update_wind(&mut self) {
        let mut rng = rand::thread_rng();
        self.wind_speed += rng.gen_range(-self.wind_variance..=self.wind_variance);
    }
}

struct FuelEfficiency {
    consumption: f32,
    consumption_variance: f32,
}

impl FuelEfficiency {
    fn new(base_consumption: f32, consumption_variance: f32) -> Self {
        FuelEfficiency {
            consumption: base_consumption,
            consumption_variance,
        }
    }

    fn adjust_consumption(&mut self) {
        let mut rng = rand::thread_rng();
        self.consumption += rng.gen_range(-self.consumption_variance..=self.consumption_variance);
    }
}

fn main() {
    let initial_altitude = 10000;
    let max_altitude = 40000;
    let altitude_step = 500;
    let initial_wind_speed = 10.0;
    let wind_variance = 5.0;
    let base_consumption = 200.0;
    let consumption_variance = 50.0;
    let trajectory = FlightTrajectory::new(initial_altitude, max_altitude, altitude_step);
    let wind_conditions = WindConditions::new(initial_wind_speed, wind_variance);
    let fuel_efficiency = FuelEfficiency::new(base_consumption, consumption_variance);
    let mut planner = CruiseAltitudePlanner::new(trajectory, wind_conditions, fuel_efficiency);
    planner.plan_cruise();
}