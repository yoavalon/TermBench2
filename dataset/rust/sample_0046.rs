fn simulate_boundary_conditions() {
    let mut state = 0;
    for _ in 0..100 {
        if state > 10 {
            break;
        }
        state += 1;
    }
    println!("{}", state);
}

fn main() {
    simulate_boundary_conditions();
}