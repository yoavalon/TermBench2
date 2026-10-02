fn simulate_thermal_state(initial_temp: i32, boundary_temp: i32, cooling_rate: i32) -> i32 {
    let mut temp = initial_temp;
    let mut steps = 0;
    while temp > boundary_temp {
        temp -= cooling_rate;
        steps += 1;
    }
    steps
}

fn main() {
    let result = simulate_thermal_state(1000, 300, 50);
    println!("{}", result);
}