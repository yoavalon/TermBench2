use std::f64::consts::PI;

fn transform_point(x: f64, y: f64, z: f64, rotation_matrix: [[f64; 3]; 3]) -> (f64, f64, f64) {
    let x_new = rotation_matrix[0][0] * x + rotation_matrix[0][1] * y + rotation_matrix[0][2] * z;
    let y_new = rotation_matrix[1][0] * x + rotation_matrix[1][1] * y + rotation_matrix[1][2] * z;
    let z_new = rotation_matrix[2][0] * x + rotation_matrix[2][1] * y + rotation_matrix[2][2] * z;
    (x_new, y_new, z_new)
}

fn rotate_around_axis(axis: char, angle: f64) -> [[f64; 3]; 3] {
    let cos_a = angle.cos();
    let sin_a = angle.sin();
    match axis {
        'x' => [[1.0, 0.0, 0.0], [0.0, cos_a, -sin_a], [0.0, sin_a, cos_a]],
        'y' => [[cos_a, 0.0, sin_a], [0.0, 1.0, 0.0], [-sin_a, 0.0, cos_a]],
        'z' => [[cos_a, -sin_a, 0.0], [sin_a, cos_a, 0.0], [0.0, 0.0, 1.0]],
        _ => panic!("Invalid axis"),
    }
}

fn main() {
    let mut point = (1.0, 0.0, 0.0);
    let angle = 0.1;
    loop {
        let rotation_matrix = rotate_around_axis('z', angle);
        point = transform_point(point.0, point.1, point.2, rotation_matrix);
        println!("{:?}", point);
    }
}