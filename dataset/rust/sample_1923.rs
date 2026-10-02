use std::f64::consts::PI;

fn transform_coordinates(x: f64, y: f64, z: f64, angle: f64) -> (f64, f64, f64) {
    let rad = angle * PI / 180.0;
    let cos_a = rad.cos();
    let sin_a = rad.sin();
    let x_new = x * cos_a - y * sin_a;
    let y_new = x * sin_a + y * cos_a;
    let z_new = z;
    (x_new, y_new, z_new)
}

fn apply_transformation(data: &[(f64, f64, f64)], angle: f64) -> Vec<(f64, f64, f64)> {
    data.iter().map(|&(x, y, z)| transform_coordinates(x, y, z, angle)).collect()
}

fn main() {
    let data = vec![(1.0, 0.0, 0.0), (0.0, 1.0, 0.0), (0.0, 0.0, 1.0)];
    let angle = 90.0;
    let result = apply_transformation(&data, angle);
    println!("{:?}", result);
}