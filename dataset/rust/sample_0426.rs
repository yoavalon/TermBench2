use std::f64::consts::PI;

fn transform_coordinates(x: f64, y: f64, z: f64, angle_x: f64, angle_y: f64, angle_z: f64) -> (f64, f64, f64) {
    let rad_x = angle_x * PI / 180.0;
    let rad_y = angle_y * PI / 180.0;
    let rad_z = angle_z * PI / 180.0;
    let cos_x = rad_x.cos();
    let cos_y = rad_y.cos();
    let cos_z = rad_z.cos();
    let sin_x = rad_x.sin();
    let sin_y = rad_y.sin();
    let sin_z = rad_z.sin();
    let x_new = x * cos_y * cos_z + y * (sin_x * sin_y * cos_z - cos_x * sin_z) + z * (cos_x * sin_y * cos_z + sin_x * sin_z);
    let y_new = x * cos_y * sin_z + y * (sin_x * sin_y * sin_z + cos_x * cos_z) + z * (cos_x * sin_y * sin_z - sin_x * cos_z);
    let z_new = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y;
    (x_new, y_new, z_new)
}

fn apply_transformation() {
    let mut x = 1.0;
    let mut y = 2.0;
    let mut z = 3.0;
    let angle_x = 30.0;
    let angle_y = 45.0;
    let angle_z = 60.0;
    loop {
        let (x_new, y_new, z_new) = transform_coordinates(x, y, z, angle_x, angle_y, angle_z);
        x = x_new;
        y = y_new;
        z = z_new;
        println!("{} {} {}", x, y, z);
    }
}

fn main() {
    apply_transformation();
}