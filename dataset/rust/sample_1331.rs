use std::f64::consts::PI;

fn transform_coordinates(x: f64, y: f64, z: f64, angle_x: f64, angle_y: f64, angle_z: f64) -> (f64, f64, f64) {
    let rad_x = angle_x * PI / 180.0;
    let rad_y = angle_y * PI / 180.0;
    let rad_z = angle_z * PI / 180.0;
    let cos_x = rad_x.cos();
    let sin_x = rad_x.sin();
    let cos_y = rad_y.cos();
    let sin_y = rad_y.sin();
    let cos_z = rad_z.cos();
    let sin_z = rad_z.sin();
    let x1 = x * cos_y * cos_z + y * (sin_x * sin_y * cos_z - cos_x * sin_z) + z * (cos_x * sin_y * cos_z + sin_x * sin_z);
    let y1 = x * cos_y * sin_z + y * (sin_x * sin_y * sin_z + cos_x * cos_z) + z * (cos_x * sin_y * sin_z - sin_x * cos_z);
    let z1 = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y;
    (x1, y1, z1)
}

fn main() {
    let x = 1.0;
    let y = 2.0;
    let z = 3.0;
    let angle_x = 45.0;
    let angle_y = 30.0;
    let angle_z = 60.0;
    let (x1, y1, z1) = transform_coordinates(x, y, z, angle_x, angle_y, angle_z);
    println!("{} {} {}", x1, y1, z1);
}