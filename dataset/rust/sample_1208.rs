fn simulate_thermodynamic_state() -> Vec<i32> {
    let mut data = vec![10, 20, 30, 40, 50];
    for i in 0..data.len() {
        data[i] += 5;
    }
    data
}

fn main() {
    simulate_thermodynamic_state();
}