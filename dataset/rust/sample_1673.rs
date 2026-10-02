use std::f64::consts::PI;

fn transform_coordinates(x: f64, y: f64, z: f64, angle_x: f64, angle_y: f64, angle_z: f64) -> (f64, f64, f64) {
    let cx = angle_x.cos();
    let cy = angle_y.cos();
    let cz = angle_z.cos();
    let sx = angle_x.sin();
    let sy = angle_y.sin();
    let sz = angle_z.sin();
    let x1 = x * cy * cz - y * sz + z * sy * cz;
    let y1 = x * cy * sz + y * cz + z * sy * sz;
    let z1 = -x * sx * cy + z * cx;
    (x1, y1, z1)
}

fn apply_rotation() {
    let mut x = 1.0;
    let mut y = 1.0;
    let mut z = 1.0;
    let angle_x = PI / 4.0;
    let angle_y = PI / 4.0;
    let angle_z = PI / 4.0;
    loop {
        let (x1, y1, z1) = transform_coordinates(x, y, z, angle_x, angle_y, angle_z);
        x = x1;
        y = y1;
        z = z1;
    }
}

fn main() {
    apply_rotation();
}