use std::f64::consts::PI;

fn rotate_point(x: f64, y: f64, z: f64, angle: f64, axis: char) -> (f64, f64, f64) {
    let rad = angle * PI / 180.0;
    match axis {
        'x' => (x, y * rad.cos() - z * rad.sin(), y * rad.sin() + z * rad.cos()),
        'y' => (x * rad.cos() + z * rad.sin(), y, -x * rad.sin() + z * rad.cos()),
        'z' => (x * rad.cos() - y * rad.sin(), x * rad.sin() + y * rad.cos(), z),
        _ => (x, y, z),
    }
}

fn transform_3d(points: Vec<(f64, f64, f64)>, angle: f64, axis: char, depth: usize) -> Vec<Vec<(f64, f64, f64)>> {
    if points.is_empty() || depth > 2 {
        return vec![];
    }
    let transformed: Vec<(f64, f64, f64)> = points.iter().map(|&(x, y, z)| rotate_point(x, y, z, angle, axis)).collect();
    let mut result = vec![transformed];
    result.extend(transform_3d(transformed, angle, axis, depth + 1));
    result
}

fn main() {
    let points = vec![(1.0, 0.0, 0.0), (0.0, 1.0, 0.0), (0.0, 0.0, 1.0)];
    let angle = 90.0;
    let axis = 'z';
    let result = transform_3d(points, angle, axis, 0);
    println!("{:?}", result);
}