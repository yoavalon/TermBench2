use std::f64::consts::PI;

fn rotate_point(x: f64, y: f64, z: f64, angle: f64) -> (f64, f64, f64) {
    let rad = angle.to_radians();
    let cos_a = rad.cos();
    let sin_a = rad.sin();
    let x_new = x * cos_a - y * sin_a;
    let y_new = x * sin_a + y * cos_a;
    (x_new, y_new, z)
}

fn transform_sequence(points: &mut [(f64, f64, f64)], angle: f64) {
    loop {
        for i in 0..points.len() {
            let (x, y, z) = points[i];
            points[i] = rotate_point(x, y, z, angle);
        }
    }
}

fn main() {
    let mut points = [(1.0, 0.0, 0.0), (0.0, 1.0, 0.0), (0.0, 0.0, 1.0)];
    let angle = 10.0;
    transform_sequence(&mut points, angle);
}