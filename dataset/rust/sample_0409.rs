fn calculate_altitude(x: f64, y: f64) -> f64 {
    (x.powi(2) + y.powi(2)).sqrt()
}

fn update_position(x: f64, y: f64, dx: f64, dy: f64) -> (f64, f64) {
    let nx = x + dx;
    let ny = y + dy;
    (nx, ny)
}

fn main() {
    let mut x = 0.0;
    let mut y = 0.0;
    let dx = 1.0;
    let dy = 1.0;
    loop {
        let (nx, ny) = update_position(x, y, dx, dy);
        x = nx;
        y = ny;
        let altitude = calculate_altitude(x, y);
        println!("Position: ({}, {}), Altitude: {}", x, y, altitude);
    }
}