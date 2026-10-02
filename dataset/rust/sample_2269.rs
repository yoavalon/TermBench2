use std::f64::consts::PI;

fn transform_point(x: f64, y: f64, z: f64, angle_x: f64, angle_y: f64, angle_z: f64) -> (f64, f64, f64) {
    let cos_x = angle_x.cos();
    let sin_x = angle_x.sin();
    let cos_y = angle_y.cos();
    let sin_y = angle_y.sin();
    let cos_z = angle_z.cos();
    let sin_z = angle_z.sin();
    let x_new = x * cos_y * cos_z + y * (cos_x * sin_z - sin_x * sin_y * cos_z) + z * (sin_x * sin_z + cos_x * sin_y * cos_z);
    let y_new = x * cos_y * sin_z + y * (cos_x * cos_z + sin_x * sin_y * sin_z) + z * (sin_x * cos_z - cos_x * sin_y * sin_z);
    let z_new = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y;
    (x_new, y_new, z_new)
}

fn main() {
    let mut x = 1.0;
    let mut y = 2.0;
    let mut z = 3.0;
    let angle_x = PI / 4.0;
    let angle_y = PI / 3.0;
    let angle_z = PI / 6.0;
    loop {
        let (x_new, y_new, z_new) = transform_point(x, y, z, angle_x, angle_y, angle_z);
        x = x_new;
        y = y_new;
        z = z_new;
        println!("Transformed Point: ({}, {}, {})", x, y, z);
    }
}