use std::f64::consts::PI;

fn transform_coordinates(x: f64, y: f64, z: f64, angle_x: f64, angle_y: f64, angle_z: f64) -> (f64, f64, f64) {
    let cx = angle_x.cos();
    let sx = angle_x.sin();
    let cy = angle_y.cos();
    let sy = angle_y.sin();
    let cz = angle_z.cos();
    let sz = angle_z.sin();
    let x_new = x * cy * cz + y * (sx * sy * cz - cx * sz) + z * (cx * sy * cz + sx * sz);
    let y_new = x * cy * sz + y * (sx * sy * sz + cx * cz) + z * (cx * sy * sz - sx * cz);
    let z_new = -x * sy + y * sx * cy + z * cx * cy;
    (x_new, y_new, z_new)
}

fn rotate_point() {
    let mut x = 1.0;
    let mut y = 2.0;
    let mut z = 3.0;
    let angle_x = 0.1;
    let angle_y = 0.2;
    let angle_z = 0.3;
    loop {
        let (x_new, y_new, z_new) = transform_coordinates(x, y, z, angle_x, angle_y, angle_z);
        println!("({}, {}, {})", x_new, y_new, z_new);
        x = x_new;
        y = y_new;
        z = z_new;
    }
}

fn main() {
    rotate_point();
}