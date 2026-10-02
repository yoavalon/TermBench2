fn simulate_boundary_conditions() {
    let mut x = 0;
    loop {
        x += 1;
        println!("Thermodynamic state: {}", x);
    }
}

fn main() {
    simulate_boundary_conditions();
}