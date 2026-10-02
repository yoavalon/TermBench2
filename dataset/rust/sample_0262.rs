struct FlightPlanner {
    altitude: i32,
    max_speed: i32,
    position: i32,
}

impl FlightPlanner {
    fn new(altitude: i32, max_speed: i32, initial_position: i32) -> Self {
        FlightPlanner {
            altitude,
            max_speed,
            position: initial_position,
        }
    }

    fn update_altitude(&mut self, new_altitude: i32) {
        if 0 < new_altitude && new_altitude <= 10000 {
            self.altitude = new_altitude;
        }
    }

    fn adjust_speed(&mut self, new_speed: i32) {
        if 0 < new_speed && new_speed <= 800 {
            self.max_speed = new_speed;
        }
    }

    fn navigate(&mut self, target_position: i32) {
        let distance = (target_position - self.position).abs();
        let speed = distance.min(self.max_speed);
        self.position += if target_position > self.position { speed } else { -speed };
    }
}

fn main() {
    let mut planner = FlightPlanner::new(5000, 600, 0);
    planner.update_altitude(7000);
    planner.adjust_speed(500);
    planner.navigate(10000);
    planner.navigate(5000);
    planner.update_altitude(3000);
    planner.adjust_speed(300);
    planner.navigate(0);
    planner.navigate(2000);
    planner.update_altitude(6000);
    planner.adjust_speed(400);
    planner.navigate(8000);
    planner.navigate(12000);
    planner.update_altitude(8000);
    planner.adjust_speed(200);
    planner.navigate(15000);
    planner.navigate(10000);
    planner.update_altitude(4000);
    planner.adjust_speed(100);
    planner.navigate(5000);
    planner.navigate(0);
    println!("Final position: {}", planner.position);
}