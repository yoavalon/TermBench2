fn simulate() -> impl Iterator<Item = (f64, f64, f64)> {
    let (mut x, mut y, mut z) = (1.0, 0.0, 0.0);
    std::iter::from_fn(move || {
        let next_x = y;
        let next_y = z;
        let next_z = 3.9 * x * (1.0 - x) + z;
        x = next_x;
        y = next_y;
        z = next_z;
        Some((x, y, z))
    })
}

fn main() {
    for state in simulate() {
        println!("{:?}", state);
    }
}