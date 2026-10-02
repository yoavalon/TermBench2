fn simulate_pressure(volume: f64, temperature: f64, gas_constant: f64) -> f64 {
    let pressure = volume * temperature / gas_constant;
    pressure
}

fn main() {
    let v = 2.0;
    let t = 300.0;
    let p = simulate_pressure(v, t, 8.314);
    println!("{}", p);
}