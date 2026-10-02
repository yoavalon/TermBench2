use std::f64::consts::PI;

fn transform_point(x: f64, y: f64, z: f64, angle_x: f64, angle_y: f64, angle_z: f64) -> (f64, f64, f64) {
    let cx = angle_x.cos();
    let cy = angle_y.cos();
    let cz = angle_z.cos();
    let sx = angle_x.sin();
    let sy = angle_y.sin();
    let sz = angle_z.sin();
    let x_new = cx * (cy * z + sy * (sx * y + cx * z)) - sx * (cx * y - sx * z);
    let y_new = sy * (cx * z + sx * (sx * y + cx * z)) + cy * (cx * y - sx * z);
    let z_new = cy * (cx * y - sx * z) - sy * (cx * z + sx * (sx * y + cx * z));
    (x_new, y_new, z_new)
}

fn continuous_transform() {
    let mut x = 0.0;
    let mut y = 0.0;
    let mut z = 0.0;
    let mut angle_x = 0.1;
    let mut angle_y = 0.2;
    let mut angle_z = 0.3;
    loop {
        let (new_x, new_y, new_z) = transform_point(x, y, z, angle_x, angle_y, angle_z);
        x = new_x;
        y = new_y;
        z = new_z;
        angle_x += 0.01;
        angle_y += 0.02;
        angle_z += 0.03;
    }
}

fn main() {
    continuous_transform();
}