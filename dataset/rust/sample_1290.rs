fn transform_coordinates(x: f64, y: f64, z: f64, a: f64, b: f64, c: f64) -> (f64, f64, f64) {
    let x1 = a * x + b * y + c * z;
    let y1 = b * x + a * y - c * z;
    let z1 = c * x + b * y + a * z;
    (x1, y1, z1)
}

fn main() {
    let x = 1.0;
    let y = 2.0;
    let z = 3.0;
    let a = 0.0;
    let b = 1.0;
    let c = 0.0;
    let (x1, y1, z1) = transform_coordinates(x, y, z, a, b, c);
    println!("{} {} {}", x1, y1, z1);
}