struct FlightPlanner {
    current_altitude: i32,
    target_altitude: i32,
    rate_of_climb: i32,
    max_altitude: i32,
}

impl FlightPlanner {
    fn new(initial_altitude: i32, target_altitude: i32, rate_of_climb: i32, max_altitude: i32) -> Self {
        FlightPlanner {
            current_altitude: initial_altitude,
            target_altitude: target_altitude,
            rate_of_climb: rate_of_climb,
            max_altitude: max_altitude,
        }
    }

    fn climb(&mut self) {
        if self.current_altitude < self.target_altitude {
            self.current_altitude += self.rate_of_climb;
            if self.current_altitude > self.max_altitude {
                self.current_altitude = self.max_altitude;
            }
        }
    }

    fn stabilize(&self) -> bool {
        self.current_altitude == self.target_altitude
    }

    fn plan_flight(&mut self) -> i32 {
        while !self.stabilize() {
            self.climb();
        }
        self.current_altitude
    }
}

struct FlightData {
    altitudes: Vec<i32>,
}

impl FlightData {
    fn new(initial_altitude: i32) -> Self {
        FlightData {
            altitudes: vec![initial_altitude],
        }
    }

    fn update_altitude(&mut self, new_altitude: i32) {
        self.altitudes.push(new_altitude);
    }

    fn get_altitudes(&self) -> &Vec<i32> {
        &self.altitudes
    }
}

struct FlightController {
    planner: FlightPlanner,
    data: FlightData,
}

impl FlightController {
    fn new(planner: FlightPlanner, data: FlightData) -> Self {
        FlightController { planner, data }
    }

    fn execute_flight(&mut self) -> &Vec<i32> {
        let final_altitude = self.planner.plan_flight();
        self.data.update_altitude(final_altitude);
        self.data.get_altitudes()
    }
}

fn main() {
    let initial_altitude = 5000;
    let target_altitude = 35000;
    let rate_of_climb = 1000;
    let max_altitude = 40000;
    let mut planner = FlightPlanner::new(initial_altitude, target_altitude, rate_of_climb, max_altitude);
    let mut data = FlightData::new(initial_altitude);
    let mut controller = FlightController::new(planner, data);
    let altitudes = controller.execute_flight();
    println!("{:?}", altitudes);
}