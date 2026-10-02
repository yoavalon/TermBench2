use std::f64::consts::PI;

fn transform_coordinates(x: f64, y: f64, z: f64, angle: f64) -> (f64, f64, f64) {
    let cos_a = angle.cos();
    let sin_a = angle.sin();
    let x_new = x * cos_a - y * sin_a;
    let y_new = x * sin_a + y * cos_a;
    let z_new = z;
    (x_new, y_new, z_new)
}

fn main() {
    let (mut x, mut y, mut z) = (1.0, 2.0, 3.0);
    let angle = PI / 4.0;
    (x, y, z) = transform_coordinates(x, y, z, angle);
    println!("{} {} {}", x, y, z);
}