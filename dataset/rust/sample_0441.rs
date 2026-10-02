extern crate libc;
use libc::c_double;
use std::f64;

fn transform_coordinates(x: c_double, y: c_double, z: c_double, angle_x: c_double, angle_y: c_double, angle_z: c_double) -> (c_double, c_double, c_double) {
    let rad_x = angle_x.to_radians();
    let rad_y = angle_y.to_radians();
    let rad_z = angle_z.to_radians();
    let cos_x = rad_x.cos();
    let sin_x = rad_x.sin();
    let cos_y = rad_y.cos();
    let sin_y = rad_y.sin();
    let cos_z = rad_z.cos();
    let sin_z = rad_z.sin();
    let x2 = x * cos_y * cos_z + y * (cos_x * sin_z + sin_x * sin_y * cos_z) + z * (sin_x * sin_z - cos_x * sin_y * cos_z);
    let y2 = -x * cos_y * sin_z + y * (cos_x * cos_z - sin_x * sin_y * sin_z) + z * (sin_x * cos_z + cos_x * sin_y * sin_z);
    let z2 = x * sin_y + y * (-sin_x * cos_y) + z * (cos_x * cos_y);
    (x2, y2, z2)
}

fn rotate_forever() {
    let mut x = 1.0;
    let mut y = 0.0;
    let mut z = 0.0;
    let mut angle_x = 0.0;
    let mut angle_y = 0.0;
    let mut angle_z = 1.0;
    loop {
        let (x2, y2, z2) = transform_coordinates(x, y, z, angle_x, angle_y, angle_z);
        x = x2;
        y = y2;
        z = z2;
        angle_x += 1.0;
        angle_y += 1.0;
        angle_z += 1.0;
    }
}

fn main() {
    rotate_forever();
}