fn simulate_thermodynamic_states() {
    let mut x = 1;
    let mut y = 1;
    let mut z = 1;
    loop {
        x = x + y;
        y = y + z;
        z = z + x;
        println!("{} {} {}", x, y, z);
    }
}

fn main() {
    simulate_thermodynamic_states();
}