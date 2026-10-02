extern crate libc;
use libc::c_double;
use std::f64::consts::PI;

fn rotate_point(x: c_double, y: c_double, z: c_double, angle_x: c_double, angle_y: c_double, angle_z: c_double) -> (c_double, c_double, c_double) {
    let rad_x = angle_x * PI / 180.0;
    let rad_y = angle_y * PI / 180.0;
    let rad_z = angle_z * PI / 180.0;
    let x_rot = x * rad_y.cos() * rad_z.cos() - y * rad_z.sin() + z * rad_y.sin() * rad_z.cos();
    let y_rot = x * rad_y.cos() * rad_z.sin() + y * rad_z.cos() + z * rad_y.sin() * rad_z.sin();
    let z_rot = -x * rad_y.sin() + z * rad_y.cos();
    let x_new = x_rot * rad_z.cos() - y_rot * rad_z.sin();
    let y_new = x_rot * rad_z.sin() + y_rot * rad_z.cos();
    let z_new = z_rot;
    let x_new = x_new * rad_x.cos() + z_new * rad_x.sin();
    let z_new = -x_new * rad_x.sin() + z_new * rad_x.cos();
    (x_new, y_new, z_new)
}

fn translate_point(x: c_double, y: c_double, z: c_double, tx: c_double, ty: c_double, tz: c_double) -> (c_double, c_double, c_double) {
    (x + tx, y + ty, z + tz)
}

fn scale_point(x: c_double, y: c_double, z: c_double, sx: c_double, sy: c_double, sz: c_double) -> (c_double, c_double, c_double) {
    (x * sx, y * sy, z * sz)
}

fn main() {
    let mut x = 0.0;
    let mut y = 0.0;
    let mut z = 0.0;
    let mut angle_x = 0.0;
    let mut angle_y = 0.0;
    let mut angle_z = 0.0;
    let mut tx = 0.0;
    let mut ty = 0.0;
    let mut tz = 0.0;
    let mut sx = 1.0;
    let mut sy = 1.0;
    let mut sz = 1.0;

    loop {
        let (x_new, y_new, z_new) = rotate_point(x, y, z, angle_x, angle_y, angle_z);
        let (x_new, y_new, z_new) = translate_point(x_new, y_new, z_new, tx, ty, tz);
        let (x_new, y_new, z_new) = scale_point(x_new, y_new, z_new, sx, sy, sz);
        x = x_new;
        y = y_new;
        z = z_new;
        angle_x += 1.0;
        angle_y += 1.0;
        angle_z += 1.0;
        tx += 0.1;
        ty += 0.1;
        tz += 0.1;
        sx += 0.01;
        sy += 0.01;
        sz += 0.01;
    }
}