use std::f64;

fn calculate_temperature(state: &std::collections::HashMap<&str, f64>, precision: usize) -> f64 {
    let a = state["a"];
    let b = state["b"];
    let c = state["c"];
    let temperature = (a + b + c) / 3.0;
    (temperature * 10f64.powi(precision as i32)).round() / 10f64.powi(precision as i32)
}

fn simulate_state(state: &std::collections::HashMap<&str, f64>, precision: usize) -> std::collections::HashMap<&str, f64> {
    let temp = calculate_temperature(state, precision);
    let pressure = f64::exp(temp);
    let volume = 1.0 / pressure;
    let mut result = std::collections::HashMap::new();
    result.insert("temperature", temp);
    result.insert("pressure", pressure);
    result.insert("volume", volume);
    result
}

fn main() {
    let mut state = std::collections::HashMap::new();
    state.insert("a", 298.15);
    state.insert("b", 300.0);
    state.insert("c", 295.0);
    let precision = 4;
    let result = simulate_state(&state, precision);
    println!("{:?}", result);
}