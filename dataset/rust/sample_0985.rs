fn flight_plan(a: f64, h: f64, d: i32) -> f64 {
    if d == 0 {
        h
    } else {
        flight_plan(a, h + a * d as f64, d - 1)
    }
}

fn main() {
    let a = 0.01;
    let h = 1000.0;
    let d = 10000;
    println!("{}", flight_plan(a, h, d));
}