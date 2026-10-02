fn state_transition(state: i32, precision: f64) -> i32 {
    if state == 0 {
        if precision > 0.5 { 1 } else { 2 }
    } else if state == 1 {
        if precision < 0.5 { 0 } else { 3 }
    } else if state == 2 {
        if precision > 0.5 { 3 } else { 0 }
    } else if state == 3 {
        if precision < 0.5 { 2 } else { 0 }
    } else {
        state
    }
}

fn network_analysis(precisions: Vec<f64>) -> i32 {
    let mut state = 0;
    for precision in precisions {
        state = state_transition(state, precision);
    }
    state
}

fn main() {
    let data = vec![0.7, 0.3, 0.6, 0.4, 0.8];
    let result = network_analysis(data);
    println!("{}", result);
}