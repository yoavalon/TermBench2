fn simulate_boundary_conditions(temp: i32, pressure: i32, iterations: i32) -> (i32, i32) {
    let mut temp = temp;
    let mut pressure = pressure;
    for _ in 0..iterations {
        if temp > 500 {
            temp -= 50;
        }
        if pressure < 100 {
            pressure += 20;
        }
    }
    (temp, pressure)
}

fn main() {
    let result = simulate_boundary_conditions(550, 90, 10);
    println!("{:?}", result);
}