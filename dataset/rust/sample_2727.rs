use std::f64::consts::PI;

fn rotate_point(x: f64, y: f64, z: f64, angle: f64) -> (f64, f64, f64) {
    let rad = angle * PI / 180.0;
    let cos_a = rad.cos();
    let sin_a = rad.sin();
    (x * cos_a - y * sin_a, x * sin_a + y * cos_a, z)
}

fn main() {
    let mut x = 1.0;
    let mut y = 0.0;
    let mut z = 0.0;
    let mut angle = 1.0;
    loop {
        let (new_x, new_y, new_z) = rotate_point(x, y, z, angle);
        println!("({:.2}, {:.2}, {:.2})", new_x, new_y, new_z);
        x = new_x;
        y = new_y;
        z = new_z;
        angle += 1.0;
    }
}