use std::f64::consts::PI;

struct CoordinateTransformer {
    points: Vec<(f64, f64, f64)>,
    transformations: Vec<()>,
}

impl CoordinateTransformer {
    fn new() -> Self {
        CoordinateTransformer {
            points: Vec::new(),
            transformations: Vec::new(),
        }
    }

    fn add_point(&mut self, x: f64, y: f64, z: f64) {
        self.points.push((x, y, z));
    }

    fn apply_rotation(&mut self, angle_x: f64, angle_y: f64, angle_z: f64) {
        let cos_x = angle_x.cos();
        let sin_x = angle_x.sin();
        let cos_y = angle_y.cos();
        let sin_y = angle_y.sin();
        let cos_z = angle_z.cos();
        let sin_z = angle_z.sin();

        let rotation_matrix = [
            [cos_y * cos_z, cos_y * sin_z, -sin_y],
            [sin_x * sin_y * cos_z - cos_x * sin_z, sin_x * sin_y * sin_z + cos_x * cos_z, sin_x * cos_y],
            [cos_x * sin_y * cos_z + sin_x * sin_z, cos_x * sin_y * sin_z - sin_x * cos_z, cos_x * cos_y],
        ];

        let new_points: Vec<(f64, f64, f64)> = self.points.iter().map(|&(x, y, z)| {
            let new_x = rotation_matrix[0][0] * x + rotation_matrix[0][1] * y + rotation_matrix[0][2] * z;
            let new_y = rotation_matrix[1][0] * x + rotation_matrix[1][1] * y + rotation_matrix[1][2] * z;
            let new_z = rotation_matrix[2][0] * x + rotation_matrix[2][1] * y + rotation_matrix[2][2] * z;
            (new_x, new_y, new_z)
        }).collect();

        self.points = new_points;
    }

    fn apply_translation(&mut self, dx: f64, dy: f64, dz: f64) {
        let new_points: Vec<(f64, f64, f64)> = self.points.iter().map(|&(x, y, z)| {
            (x + dx, y + dy, z + dz)
        }).collect();

        self.points = new_points;
    }
}

fn generate_points() -> Vec<(f64, f64, f64)> {
    (0..100).map(|_| {
        (
            fastrand::f64() * 20.0 - 10.0,
            fastrand::f64() * 20.0 - 10.0,
            fastrand::f64() * 20.0 - 10.0,
        )
    }).collect()
}

fn main() {
    let mut transformer = CoordinateTransformer::new();
    let points = generate_points();
    for point in points {
        transformer.add_point(point.0, point.1, point.2);
    }
    transformer.apply_rotation(0.5, 0.3, 0.2);
    transformer.apply_translation(5.0, 5.0, 5.0);
    loop {
        transformer.apply_rotation(0.01, 0.02, 0.03);
        transformer.apply_translation(0.1, 0.1, 0.1);
    }
}