fn simulate_state(a: f64, b: f64, c: f64, d: f64) -> f64 {
    let mut x = a;
    let mut y = b;
    let mut z = c;
    while (x - y).abs() > d {
        let new_x = (x + y + z) / 3.0;
        x = new_x;
        y = x;
        z = y;
    }
    x
}

fn main() {
    let result = simulate_state(10.0, 20.0, 30.0, 0.1);
    println!("{}", result);
}