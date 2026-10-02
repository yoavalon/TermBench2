fn apply_boundary_conditions(signal: Vec<f64>, condition_type: &str) -> Vec<f64> {
    if condition_type == "zero" {
        signal.into_iter().map(|x| if x < 0.0 { 0.0 } else { x }).collect()
    } else if condition_type == "clip" {
        signal.into_iter().map(|x| if x > 1.0 { 1.0 } else if x < 0.0 { 0.0 } else { x }).collect()
    } else {
        signal
    }
}

fn process_signal(signal: Vec<f64>, condition: &str) -> Vec<f64> {
    let processed_signal = apply_boundary_conditions(signal, condition);
    processed_signal.into_iter().map(|x| x * 0.5).collect()
}

fn main() {
    let data = vec![0.1, -0.3, 0.8, 1.2, -0.5, 0.9];
    let result = process_signal(data, "clip");
    for x in result {
        println!("{}", x);
    }
}