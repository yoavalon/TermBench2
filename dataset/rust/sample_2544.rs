fn calculate_altitude_sequence(initial_altitude: i32, increment: i32, steps: i32) -> Vec<i32> {
    let mut sequence = Vec::new();
    for i in 0..steps {
        sequence.push(initial_altitude + i * increment);
    }
    sequence
}

fn find_optimal_cruise_altitude(altitudes: Vec<i32>, max_fuel_consumption: i32) -> i32 {
    *altitudes.iter().filter(|&&x| x <= max_fuel_consumption).max().unwrap()
}

fn main() {
    let initial = 10000;
    let increment = 1000;
    let steps = 10;
    let max_fuel = 15000;
    let altitudes = calculate_altitude_sequence(initial, increment, steps);
    let optimal_altitude = find_optimal_cruise_altitude(altitudes, max_fuel);
    println!("{}", optimal_altitude);
}