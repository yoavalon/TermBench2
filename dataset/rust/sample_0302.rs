use std::f64::consts::PI;

fn transform_coordinates(x: f64, y: f64, z: f64, angle: f64) -> (f64, f64, f64) {
    let cos_a = angle.cos();
    let sin_a = angle.sin();
    let x_new = x * cos_a - y * sin_a;
    let y_new = x * sin_a + y * cos_a;
    (x_new, y_new, z)
}

fn main() {
    let mut angle = 0.0;
    let mut x = 1.0;
    let mut y = 0.0;
    let mut z = 0.0;
    loop {
        let (x_new, y_new, z_new) = transform_coordinates(x, y, z, angle);
        x = x_new;
        y = y_new;
        z = z_new;
        angle += 0.01;
    }
}