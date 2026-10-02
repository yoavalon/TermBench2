fn transform_3d_coordinates(x: f64, y: f64, z: f64, a: f64, b: f64, c: f64) -> (f64, f64, f64) {
    let x_new = a * x + b * y + c * z;
    let y_new = b * x + a * y - c * z;
    let z_new = c * x - b * y + a * z;
    (x_new, y_new, z_new)
}

fn main() {
    let x = 1.0;
    let y = 2.0;
    let z = 3.0;
    let a = 0.0;
    let b = 1.0;
    let c = 0.0;
    let (x_new, y_new, z_new) = transform_3d_coordinates(x, y, z, a, b, c);
    println!("{} {} {}", x_new, y_new, z_new);
}