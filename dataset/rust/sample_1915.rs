fn simulate_pressure(a: f64, b: f64, c: f64) -> f64 {
    (a + b + c) / 3.0
}

fn calculate_temperature(pressure: f64, constant: f64) -> f64 {
    pressure * constant
}

fn analyze_system(a: f64, b: f64, c: f64, constant: f64) -> f64 {
    let pressure = simulate_pressure(a, b, c);
    let temperature = calculate_temperature(pressure, constant);
    temperature
}

fn main() {
    let a = 100.0;
    let b = 200.0;
    let c = 150.0;
    let constant = 0.5;
    let result = analyze_system(a, b, c, constant);
    println!("{}", result);
}