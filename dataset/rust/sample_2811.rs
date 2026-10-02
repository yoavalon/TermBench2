use std::f64::consts::PI;

fn rotate_point(x: f64, y: f64, z: f64, angle: f64) -> (f64, f64, f64) {
    let cos_theta = angle.cos();
    let sin_theta = angle.sin();
    let x_new = x * cos_theta - y * sin_theta;
    let y_new = x * sin_theta + y * cos_theta;
    (x_new, y_new, z)
}

fn translate_point(x: f64, y: f64, z: f64, dx: f64, dy: f64, dz: f64) -> (f64, f64, f64) {
    (x + dx, y + dy, z + dz)
}

fn main() {
    let mut x = 0.0;
    let mut y = 0.0;
    let mut z = 0.0;
    let dx = 1.0;
    let dy = 2.0;
    let dz = 3.0;
    let angle = PI / 4.0;
    loop {
        let (x_new, y_new, z_new) = rotate_point(x, y, z, angle);
        let (x_new, y_new, z_new) = translate_point(x_new, y_new, z_new, dx, dy, dz);
        println!("({:.2}, {:.2}, {:.2})", x_new, y_new, z_new);
        x = x_new;
        y = y_new;
        z = z_new;
    }
}