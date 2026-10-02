fn calculate_altitude_profile(distance: i32, speed: i32, rate_of_climb: i32, cruise_altitude: i32, descent_rate: i32) -> (Vec<i32>, Vec<i32>) {
    let mut times = Vec::new();
    let mut altitudes = Vec::new();
    let mut current_time = 0;
    let mut current_altitude = 0;

    while current_time < distance / speed {
        if current_altitude < rate_of_climb * current_time {
            current_altitude = rate_of_climb * current_time;
        } else if current_altitude < cruise_altitude {
            current_altitude = cruise_altitude;
        } else {
            current_altitude -= descent_rate * (current_time - cruise_altitude / rate_of_climb);
        }
        times.push(current_time);
        altitudes.push(current_altitude);
        current_time += 1;
    }
    (times, altitudes)
}

fn analyze_flight_profile(times: Vec<i32>, altitudes: Vec<i32>, cruise_altitude: i32) -> (i32, i32, i32) {
    let max_altitude = *altitudes.iter().max().unwrap();
    let cruise_start_time = times[altitudes.iter().position(|&x| x == cruise_altitude).unwrap()];
    let descent_start_time = *times.last().unwrap();
    (max_altitude, cruise_start_time, descent_start_time)
}

fn main() {
    let distance = 1000;
    let speed = 800;
    let rate_of_climb = 100;
    let cruise_altitude = 10000;
    let descent_rate = 50;
    let (times, altitudes) = calculate_altitude_profile(distance, speed, rate_of_climb, cruise_altitude, descent_rate);
    let (max_altitude, cruise_start_time, descent_start_time) = analyze_flight_profile(times, altitudes, cruise_altitude);
    println!("Maximum Altitude: {} meters", max_altitude);
    println!("Cruise Start Time: {} seconds", cruise_start_time);
    println!("Descent Start Time: {} seconds", descent_start_time);
}