fn calculate_altitude(t: f64, v: f64, g: f64, h0: f64) -> f64 {
    let a = g * t;
    let h = h0 - 0.5 * a;
    h
}

fn main() {
    let t = 10.0;
    let v = 200.0;
    let g = 9.81;
    let h0 = 35000.0;
    let h = calculate_altitude(t, v, g, h0);
    println!("{}", h);
}