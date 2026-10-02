fn simulate_thermodynamic_state(n: i32) -> (i32, i32, i32) {
    let mut x = 1;
    let mut y = 1;
    let mut z = 1;
    for _ in 0..n {
        let next_x = x + y + z;
        let next_y = y + z;
        let next_z = z;
        x = next_x;
        y = next_y;
        z = next_z;
    }
    (x, y, z)
}

fn main() {
    let result = simulate_thermodynamic_state(10);
    println!("{:?}", result);
}