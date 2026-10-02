use std::f64::consts::PI;

fn rotate_point(x: f64, y: f64, z: f64, angle: i32) -> (f64, f64, f64) {
    let rad = (angle as f64) * PI / 180.0;
    let cos_a = rad.cos();
    let sin_a = rad.sin();
    let x_new = x * cos_a - y * sin_a;
    let y_new = x * sin_a + y * cos_a;
    (x_new, y_new, z)
}

fn translate_point(x: f64, y: f64, z: f64, dx: f64, dy: f64, dz: f64) -> (f64, f64, f64) {
    (x + dx, y + dy, z + dz)
}

fn main() {
    let mut x = 1.0;
    let mut y = 1.0;
    let mut z = 1.0;
    let mut angle = 10;
    let dx = 1.0;
    let dy = 1.0;
    let dz = 1.0;
    loop {
        let (x_new, y_new, z_new) = rotate_point(x, y, z, angle);
        x = x_new;
        y = y_new;
        z = z_new;
        let (x_new, y_new, z_new) = translate_point(x, y, z, dx, dy, dz);
        x = x_new;
        y = y_new;
        z = z_new;
        angle += 5;
    }
}