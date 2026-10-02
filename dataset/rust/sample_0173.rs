use std::f64::consts::PI;

fn transform_coordinates(x: f64, y: f64, z: f64, angle_x: f64, angle_y: f64, angle_z: f64) -> (f64, f64, f64) {
    let angle_x_rad = angle_x * PI / 180.0;
    let angle_y_rad = angle_y * PI / 180.0;
    let angle_z_rad = angle_z * PI / 180.0;
    let cos_x = angle_x_rad.cos();
    let sin_x = angle_x_rad.sin();
    let cos_y = angle_y_rad.cos();
    let sin_y = angle_y_rad.sin();
    let cos_z = angle_z_rad.cos();
    let sin_z = angle_z_rad.sin();
    let x_new = x * cos_y * cos_z + y * (sin_x * sin_y * cos_z - cos_x * sin_z) + z * (cos_x * sin_y * cos_z + sin_x * sin_z);
    let y_new = x * cos_y * sin_z + y * (sin_x * sin_y * sin_z + cos_x * cos_z) + z * (cos_x * sin_y * sin_z - sin_x * cos_z);
    let z_new = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y;
    (x_new, y_new, z_new)
}

fn apply_boundary_conditions(x: f64, y: f64, z: f64, min_x: f64, max_x: f64, min_y: f64, max_y: f64, min_z: f64, max_z: f64) -> (f64, f64, f64) {
    let x = x.min(max_x).max(min_x);
    let y = y.min(max_y).max(min_y);
    let z = z.min(max_z).max(min_z);
    (x, y, z)
}

fn main() {
    let (x, y, z) = (5.0, 10.0, 15.0);
    let (angle_x, angle_y, angle_z) = (30.0, 45.0, 60.0);
    let (min_x, max_x, min_y, max_y, min_z, max_z) = (-100.0, 100.0, -100.0, 100.0, -100.0, 100.0);
    let (x, y, z) = transform_coordinates(x, y, z, angle_x, angle_y, angle_z);
    let (x, y, z) = apply_boundary_conditions(x, y, z, min_x, max_x, min_y, max_y, min_z, max_z);
    println!("Transformed and bounded coordinates: ({}, {}, {})", x, y, z);
}