use std::f64::consts::PI;

fn transform_coordinates(x: f64, y: f64, z: f64, angle: f64) -> (f64, f64, f64) {
    let rad = angle * PI / 180.0;
    let cos_a = rad.cos();
    let sin_a = rad.sin();
    let x_new = x * cos_a - y * sin_a;
    let y_new = x * sin_a + y * cos_a;
    (x_new, y_new, z)
}

fn infinite_rotation(mut x: f64, mut y: f64, mut z: f64, angle_step: f64) {
    let mut angle = 0.0;
    loop {
        let (x_new, y_new, z_new) = transform_coordinates(x, y, z, angle);
        x = x_new;
        y = y_new;
        z = z_new;
        angle += angle_step;
    }
}

fn main() {
    let x = 1.0;
    let y = 1.0;
    let z = 1.0;
    let angle_step = 5.0;
    infinite_rotation(x, y, z, angle_step);
}