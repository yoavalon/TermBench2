use std::f64::consts::PI;

fn rotate_point(x: f64, y: f64, z: f64, angle: f64, axis: &str) -> (f64, f64, f64) {
    let cos_a = angle.cos();
    let sin_a = angle.sin();
    match axis {
        "x" => (x, cos_a * y - sin_a * z, sin_a * y + cos_a * z),
        "y" => (cos_a * x + sin_a * z, y, -sin_a * x + cos_a * z),
        "z" => (cos_a * x - sin_a * y, sin_a * x + cos_a * y, z),
        _ => (x, y, z),
    }
}

fn scale_point(x: f64, y: f64, z: f64, scale_x: f64, scale_y: f64, scale_z: f64) -> (f64, f64, f64) {
    (x * scale_x, y * scale_y, z * scale_z)
}

fn transform_sequence(point: (f64, f64, f64), rotations: &[(f64, &str)], scales: &[(f64, f64, f64)]) -> (f64, f64, f64) {
    let (mut x, mut y, mut z) = point;
    for &(angle, axis) in rotations {
        (x, y, z) = rotate_point(x, y, z, angle, axis);
    }
    for &(scale_x, scale_y, scale_z) in scales {
        (x, y, z) = scale_point(x, y, z, scale_x, scale_y, scale_z);
    }
    (x, y, z)
}

fn main() {
    let initial_point = (1.0, 1.0, 1.0);
    let rotations = [(PI / 4.0, "x"), (PI / 4.0, "y")];
    let scales = [(2.0, 2.0, 2.0)];
    loop {
        let new_point = transform_sequence(initial_point, &rotations, &scales);
        println!("{:?}", new_point);
    }
}