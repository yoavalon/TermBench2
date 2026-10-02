use std::f64::consts::PI;

fn transform_coordinates(x: f64, y: f64, z: f64, angle: f64) -> (f64, f64, f64) {
    let rad = angle.to_radians();
    let cos_rad = rad.cos();
    let sin_rad = rad.sin();
    let x_new = x * cos_rad - y * sin_rad;
    let y_new = x * sin_rad + y * cos_rad;
    let z_new = z;
    (x_new, y_new, z_new)
}

fn continuous_transform(mut x: f64, mut y: f64, mut z: f64, angle_increment: f64) {
    loop {
        let (x_new, y_new, z_new) = transform_coordinates(x, y, z, angle_increment);
        println!("({}, {}, {})", x_new, y_new, z_new);
        x = x_new;
        y = y_new;
        z = z_new;
    }
}

fn main() {
    let x = 1.0;
    let y = 0.0;
    let z = 0.0;
    let angle_increment = 5.0;
    continuous_transform(x, y, z, angle_increment);
}