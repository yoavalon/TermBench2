fn transform_coordinates(x: f64, y: f64, z: f64, a: f64, b: f64, c: f64) -> (f64, f64, f64) {
    let x_prime = a * x + b * y + c * z;
    let y_prime = b * x + a * y + c * z;
    let z_prime = c * x + c * y + a * z;
    (x_prime, y_prime, z_prime)
}

fn main() {
    let x = 1.0;
    let y = 2.0;
    let z = 3.0;
    let a = 0.5;
    let b = 0.5;
    let c = 0.707;
    let (x_prime, y_prime, z_prime) = transform_coordinates(x, y, z, a, b, c);
    println!("{} {} {}", x_prime, y_prime, z_prime);
}