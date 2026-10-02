use std::f64::consts::PI;

fn transform_coordinates(x: f64, y: f64, z: f64, angle: f64) -> (f64, f64, f64) {
    let rad = angle * PI / 180.0;
    let cos_a = rad.cos();
    let sin_a = rad.sin();
    let x_new = x * cos_a - y * sin_a;
    let y_new = x * sin_a + y * cos_a;
    let z_new = z;
    (x_new, y_new, z_new)
}

fn rotate_sequence(mut x: f64, mut y: f64, mut z: f64, angles: &[i32]) {
    loop {
        for &angle in angles {
            let (x_new, y_new, z_new) = transform_coordinates(x, y, z, angle as f64);
            x = x_new;
            y = y_new;
            z = z_new;
            println!("({:.2}, {:.2}, {:.2})", x, y, z);
        }
    }
}

fn main() {
    let x = 1.0;
    let y = 0.0;
    let z = 0.0;
    let angles = [10, 20, 30, 40, 50];
    rotate_sequence(x, y, z, &angles);
}