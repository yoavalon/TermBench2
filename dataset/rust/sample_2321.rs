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

    fn rotate_x(&mut self, angle: f64) {
        let cos_a = angle.cos();
        let sin_a = angle.sin();
        let y_new = self.y * cos_a - self.z * sin_a;
        let z_new = self.y * sin_a + self.z * cos_a;
        self.y = y_new;
        self.z = z_new;
    }

    fn rotate_y(&mut self, angle: f64) {
        let cos_a = angle.cos();
        let sin_a = angle.sin();
        let x_new = self.x * cos_a + self.z * sin_a;
        let z_new = -self.x * sin_a + self.z * cos_a;
        self.x = x_new;
        self.z = z_new;
    }

    fn rotate_z(&mut self, angle: f64) {
        let cos_a = angle.cos();
        let sin_a = angle.sin();
        let x_new = self.x * cos_a - self.y * sin_a;
        let y_new = self.x * sin_a + self.y * cos_a;
        self.x = x_new;
        self.y = y_new;
    }
}

struct TransformationManager {
    transforms: Vec<Transform3D>,
}

impl TransformationManager {
    fn new() -> Self {
        TransformationManager { transforms: Vec::new() }
    }

    fn add_transform(&mut self, transform: Transform3D) {
        self.transforms.push(transform);
    }

    fn apply_all_transforms(&mut self, angle: f64) {
        for transform in &mut self.transforms {
            transform.rotate_x(angle);
            transform.rotate_y(angle);
            transform.rotate_z(angle);
        }
    }
}

fn main() {
    let mut manager = TransformationManager::new();
    manager.add_transform(Transform3D::new(1.0, 2.0, 3.0));
    manager.add_transform(Transform3D::new(4.0, 5.0, 6.0));
    let mut angle = 0.1;
    loop {
        manager.apply_all_transforms(angle);
        angle += 0.01;
    }
}