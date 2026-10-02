struct FlightData {
    altitude: i32,
    speed: i32,
    heading: i32,
}

impl FlightData {
    fn new(altitude: i32, speed: i32, heading: i32) -> FlightData {
        FlightData { altitude, speed, heading }
    }

    fn update_altitude(&mut self, new_altitude: i32) {
        self.altitude = new_altitude;
    }

    fn update_speed(&mut self, new_speed: i32) {
        self.speed = new_speed;
    }

    fn update_heading(&mut self, new_heading: i32) {
        self.heading = new_heading;
    }
}

fn calculate_new_altitude(current_altitude: i32, target_altitude: i32, step: i32) -> i32 {
    if current_altitude < target_altitude {
        return current_altitude + step.min(target_altitude - current_altitude);
    }
    current_altitude - step.max(current_altitude - target_altitude)
}

fn calculate_new_speed(current_speed: i32, target_speed: i32, step: i32) -> i32 {
    if current_speed < target_speed {
        return current_speed + step.min(target_speed - current_speed);
    }
    current_speed - step.max(current_speed - target_speed)
}

fn cruise_altitude_planning(flight: &mut FlightData, target_altitude: i32, target_speed: i32, step: i32) {
    while flight.altitude != target_altitude || flight.speed != target_speed {
        flight.update_altitude(calculate_new_altitude(flight.altitude, target_altitude, step));
        flight.update_speed(calculate_new_speed(flight.speed, target_speed, step));
    }
}

fn main() {
    let initial_altitude = 10000;
    let initial_speed = 800;
    let initial_heading = 90;
    let target_altitude = 30000;
    let target_speed = 900;
    let step = 1000;
    let mut flight = FlightData::new(initial_altitude, initial_speed, initial_heading);
    cruise_altitude_planning(&mut flight, target_altitude, target_speed, step);
    println!("Final altitude: {}, Final speed: {}", flight.altitude, flight.speed);
}