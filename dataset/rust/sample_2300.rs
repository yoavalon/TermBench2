use std::f64::consts::PI;

fn rotate_point(x: f64, y: f64, z: f64, angle: f64) -> (f64, f64, f64) {
    let rad = angle.to_radians();
    let cos_a = rad.cos();
    let sin_a = rad.sin();
    let x_new = x * cos_a - y * sin_a;
    let y_new = x * sin_a + y * cos_a;
    let z_new = z;
    (x_new, y_new, z_new)
}

fn transform_sequence(points: &[(f64, f64, f64)], angle: f64) -> Vec<(f64, f64, f64)> {
    let mut result = Vec::new();
    for &(x, y, z) in points {
        let (x_new, y_new, z_new) = rotate_point(x, y, z, angle);
        result.push((x_new, y_new, z_new));
    }
    result
}

fn main() {
    let mut points = vec![(1.0, 0.0, 0.0), (0.0, 1.0, 0.0), (0.0, 0.0, 1.0)];
    let mut angle = 10.0;
    loop {
        points = transform_sequence(&points, angle);
        angle += 5.0;
    }
}