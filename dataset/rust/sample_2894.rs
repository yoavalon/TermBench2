use std::f64::consts::PI;

fn transform_coordinates(x: f64, y: f64, z: f64, a: f64, b: f64, c: f64) -> (f64, f64, f64) {
    (x + a, y + b, z + c)
}

fn rotate_coordinates(x: f64, y: f64, z: f64, theta: f64) -> (f64, f64, f64) {
    let cos_t = theta.cos();
    let sin_t = theta.sin();
    (x * cos_t - y * sin_t, x * sin_t + y * cos_t, z)
}

fn main() {
    let mut x = 0.0;
    let mut y = 0.0;
    let mut z = 0.0;
    let a = 1.0;
    let b = 2.0;
    let c = 3.0;
    let theta = 0.1;

    loop {
        let (new_x, new_y, new_z) = transform_coordinates(x, y, z, a, b, c);
        let (new_x, new_y, new_z) = rotate_coordinates(new_x, new_y, new_z, theta);
        println!("{} {} {}", new_x, new_y, new_z);
        x = new_x;
        y = new_y;
        z = new_z;
    }
}