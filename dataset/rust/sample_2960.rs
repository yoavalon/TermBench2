use std::f64::consts::PI;

struct CoordinateTransformer {
    x: f64,
    y: f64,
    z: f64,
}

impl CoordinateTransformer {
    fn new(x: f64, y: f64, z: f64) -> Self {
        CoordinateTransformer { x, y, z }
    }

    fn rotate_x(&mut self, angle: f64) {
        let cos_a = angle.cos();
        let sin_a = angle.sin();
        let new_y = self.y * cos_a - self.z * sin_a;
        let new_z = self.y * sin_a + self.z * cos_a;
        self.y = new_y;
        self.z = new_z;
    }

    fn rotate_y(&mut self, angle: f64) {
        let cos_a = angle.cos();
        let sin_a = angle.sin();
        let new_x = self.x * cos_a + self.z * sin_a;
        let new_z = -self.x * sin_a + self.z * cos_a;
        self.x = new_x;
        self.z = new_z;
    }

    fn rotate_z(&mut self, angle: f64) {
        let cos_a = angle.cos();
        let sin_a = angle.sin();
        let new_x = self.x * cos_a - self.y * sin_a;
        let new_y = self.x * sin_a + self.y * cos_a;
        self.x = new_x;
        self.y = new_y;
    }

    fn scale(&mut self, factor: f64) {
        self.x *= factor;
        self.y *= factor;
        self.z *= factor;
    }
}

fn generate_angles() -> impl Iterator<Item = f64> {
    let mut angle = 0.0;
    std::iter::from_fn(move || {
        let current_angle = angle;
        angle += PI / 180.0;
        Some(current_angle)
    })
}

fn transform_sequence(transformer: &mut CoordinateTransformer, angles: impl Iterator<Item = f64>) {
    for angle in angles {
        transformer.rotate_x(angle);
        transformer.rotate_y(angle);
        transformer.rotate_z(angle);
        transformer.scale(1.01);
    }
}

fn main() {
    let mut transformer = CoordinateTransformer::new(1.0, 0.0, 0.0);
    let angles = generate_angles();
    transform_sequence(&mut transformer, angles);
}