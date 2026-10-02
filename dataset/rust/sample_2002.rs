use std::f64::consts::PI;

struct Transform3D {
    x: f64,
    y: f64,
    z: f64,
}

impl Transform3D {
    fn new(x: f64, y: f64, z: f64) -> Self {
        Transform3D { x, y, z }
    }

    fn rotate_x(&self, angle: f64) -> Transform3D {
        let cos_a = angle.cos();
        let sin_a = angle.sin();
        let new_y = self.y * cos_a - self.z * sin_a;
        let new_z = self.y * sin_a + self.z * cos_a;
        Transform3D::new(self.x, new_y, new_z)
    }

    fn rotate_y(&self, angle: f64) -> Transform3D {
        let cos_a = angle.cos();
        let sin_a = angle.sin();
        let new_x = self.x * cos_a + self.z * sin_a;
        let new_z = -self.x * sin_a + self.z * cos_a;
        Transform3D::new(new_x, self.y, new_z)
    }

    fn rotate_z(&self, angle: f64) -> Transform3D {
        let cos_a = angle.cos();
        let sin_a = angle.sin();
        let new_x = self.x * cos_a - self.y * sin_a;
        let new_y = self.x * sin_a + self.y * cos_a;
        Transform3D::new(new_x, new_y, self.z)
    }
}

struct TransformHandler {
    points: Vec<Transform3D>,
}

impl TransformHandler {
    fn new(points: Vec<(f64, f64, f64)>) -> Self {
        TransformHandler {
            points: points.into_iter().map(|p| Transform3D::new(p.0, p.1, p.2)).collect(),
        }
    }

    fn apply_rotation(&self, angle_x: f64, angle_y: f64, angle_z: f64) -> Vec<(f64, f64, f64)> {
        let mut rotated_points = Vec::new();
        for point in &self.points {
            let rotated = point.rotate_x(angle_x).rotate_y(angle_y).rotate_z(angle_z);
            rotated_points.push((rotated.x, rotated.y, rotated.z));
        }
        rotated_points
    }
}

fn main() {
    let initial_points = vec![(1.0, 0.0, 0.0), (0.0, 1.0, 0.0), (0.0, 0.0, 1.0)];
    let handler = TransformHandler::new(initial_points);
    let angles = (PI / 4.0, PI / 4.0, PI / 4.0);
    let result = handler.apply_rotation(angles.0, angles.1, angles.2);
    for point in result {
        println!("{:?}", point);
    }
}