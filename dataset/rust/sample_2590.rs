fn calculate_altitude_change(current_alt: i32, target_alt: i32, rate: i32) -> i32 {
    if current_alt < target_alt {
        return current_alt.min(target_alt);
    } else {
        return current_alt.max(target_alt);
    }
}

fn simulate_flight_trajectory(initial_alt: i32, target_alt: i32, rate: i32, steps: i32) -> Vec<i32> {
    let mut altitude = initial_alt;
    let mut trajectory = vec![altitude];
    for _ in 0..steps {
        altitude = calculate_altitude_change(altitude, target_alt, rate);
        trajectory.push(altitude);
        if altitude == target_alt {
            break;
        }
    }
    trajectory
}

fn main() {
    let initial_altitude = 10000;
    let target_altitude = 30000;
    let rate_of_change = 1500;
    let simulation_steps = 100;
    let result = simulate_flight_trajectory(initial_altitude, target_altitude, rate_of_change, simulation_steps);
    println!("{:?}", result);
}