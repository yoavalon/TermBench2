use std::f64::consts::PI;

fn transform_point(x: f64, y: f64, z: f64, angle_x: f64, angle_y: f64, angle_z: f64) -> (f64, f64, f64) {
    let rad_x = angle_x * PI / 180.0;
    let rad_y = angle_y * PI / 180.0;
    let rad_z = angle_z * PI / 180.0;
    let cos_x = rad_x.cos();
    let sin_x = rad_x.sin();
    let cos_y = rad_y.cos();
    let sin_y = rad_y.sin();
    let cos_z = rad_z.cos();
    let sin_z = rad_z.sin();
    let x1 = x;
    let y1 = y * cos_x - z * sin_x;
    let z1 = y * sin_x + z * cos_x;
    let x2 = x1 * cos_y + z1 * sin_y;
    let y2 = y1;
    let z2 = -x1 * sin_y + z1 * cos_y;
    let x3 = x2 * cos_z - y2 * sin_z;
    let y3 = x2 * sin_z + y2 * cos_z;
    let z3 = z2;
    (x3, y3, z3)
}

fn rotate_forever() {
    let mut angle_x = 0.0;
    let mut angle_y = 0.0;
    let mut angle_z = 0.0;
    loop {
        let (x, y, z) = (1.0, 1.0, 1.0);
        let (x, y, z) = transform_point(x, y, z, angle_x, angle_y, angle_z);
        angle_x += 1.0;
        angle_y += 2.0;
        angle_z += 3.0;
    }
}

fn main() {
    rotate_forever();
}