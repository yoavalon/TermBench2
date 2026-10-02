use std::f64::consts::PI;

fn transform_coordinates(x: f64, y: f64, z: f64, angle: f64) -> (f64, f64, f64) {
    let rad = angle * PI / 180.0;
    let cos_a = rad.cos();
    let sin_a = rad.sin();
    let new_x = x * cos_a - y * sin_a;
    let new_y = x * sin_a + y * cos_a;
    let new_z = z;
    (new_x, new_y, new_z)
}

fn calculate_distance(x1: f64, y1: f64, z1: f64, x2: f64, y2: f64, z2: f64) -> f64 {
    ((x2 - x1).powi(2) + (y2 - y1).powi(2) + (z2 - z1).powi(2)).sqrt()
}

fn main() {
    let x = 1.0;
    let y = 2.0;
    let z = 3.0;
    let angle = 30.0;
    let (x_t, y_t, z_t) = transform_coordinates(x, y, z, angle);
    let d = calculate_distance(x, y, z, x_t, y_t, z_t);
    println!("Transformed Coordinates: ({}, {}, {})", x_t, y_t, z_t);
    println!("Distance: {}", d);
}