use std::f64::consts::PI;

fn transform_point(x: f64, y: f64, z: f64, angle_x: f64, angle_y: f64, angle_z: f64) -> (f64, f64, f64) {
    let cos_x = angle_x.cos();
    let sin_x = angle_x.sin();
    let cos_y = angle_y.cos();
    let sin_y = angle_y.sin();
    let cos_z = angle_z.cos();
    let sin_z = angle_z.sin();
    let x_new = cos_y * (cos_z * x + sin_z * y) + sin_y * z;
    let y_new = cos_x * (sin_y * (cos_z * x + sin_z * y) - cos_y * z) - sin_x * (sin_z * x - cos_z * y);
    let z_new = sin_x * (sin_y * (cos_z * x + sin_z * y) - cos_y * z) + cos_x * (sin_z * x - cos_z * y);
    (x_new, y_new, z_new)
}

fn continuous_rotation() {
    let mut x = 0.0;
    let mut y = 0.0;
    let mut z = 0.0;
    let mut angle_x = 0.0;
    let mut angle_y = 0.0;
    let mut angle_z = 0.0;
    let increment = 0.01;
    loop {
        angle_x += increment;
        angle_y += increment;
        angle_z += increment;
        let (x_new, y_new, z_new) = transform_point(x, y, z, angle_x, angle_y, angle_z);
        x = x_new;
        y = y_new;
        z = z_new;
    }
}

fn main() {
    continuous_rotation();
}