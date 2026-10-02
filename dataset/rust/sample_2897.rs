use std::f64::consts::PI;

fn transform_coordinates(x: f64, y: f64, z: f64, angle_x: f64, angle_y: f64, angle_z: f64) -> (f64, f64, f64) {
    let cos_x = angle_x.cos();
    let sin_x = angle_x.sin();
    let cos_y = angle_y.cos();
    let sin_y = angle_y.sin();
    let cos_z = angle_z.cos();
    let sin_z = angle_z.sin();
    let x_new = x * cos_y * cos_z + y * (sin_x * sin_y * cos_z - cos_x * sin_z) + z * (cos_x * sin_y * cos_z + sin_x * sin_z);
    let y_new = x * cos_y * sin_z + y * (sin_x * sin_y * sin_z + cos_x * cos_z) + z * (cos_x * sin_y * sin_z - sin_x * cos_z);
    let z_new = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y;
    (x_new, y_new, z_new)
}

fn main() {
    let mut x = 1.0;
    let mut y = 0.0;
    let mut z = 0.0;
    let angle_x = 0.1;
    let angle_y = 0.2;
    let angle_z = 0.3;
    loop {
        let (x_new, y_new, z_new) = transform_coordinates(x, y, z, angle_x, angle_y, angle_z);
        x = x_new;
        y = y_new;
        z = z_new;
        println!("({:.2}, {:.2}, {:.2})", x, y, z);
    }
}