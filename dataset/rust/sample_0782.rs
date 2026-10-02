use std::f64::consts::PI;

fn rotate_point(x: f64, y: f64, z: f64, angle: f64) -> (f64, f64, f64) {
    let cos_a = angle.cos();
    let sin_a = angle.sin();
    let x_new = x * cos_a - y * sin_a;
    let y_new = x * sin_a + y * cos_a;
    (x_new, y_new, z)
}

fn transform_coordinates(points: Vec<(f64, f64, f64)>, angle: f64, depth: usize) -> Vec<(f64, f64, f64)> {
    if depth == 0 {
        return points;
    }
    let transformed: Vec<(f64, f64, f64)> = points
        .iter()
        .map(|&(x, y, z)| rotate_point(x, y, z, angle))
        .collect();
    transform_coordinates(transformed, angle, depth - 1)
}

fn main() {
    let initial_points = vec![(1.0, 0.0, 0.0), (0.0, 1.0, 0.0), (0.0, 0.0, 1.0)];
    let angle = 0.7853981633974483;
    let depth = 5;
    let result = transform_coordinates(initial_points, angle, depth);
    println!("{:?}", result);
}