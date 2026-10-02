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

    fn translate(&mut self, dx: f64, dy: f64, dz: f64) {
        self.x += dx;
        self.y += dy;
        self.z += dz;
    }

    fn rotate_x(&mut self, angle: f64) {
        let rad = angle.to_radians();
        let y = self.y;
        let z = self.z;
        self.y = y * rad.cos() - z * rad.sin();
        self.z = y * rad.sin() + z * rad.cos();
    }

    fn rotate_y(&mut self, angle: f64) {
        let rad = angle.to_radians();
        let x = self.x;
        let z = self.z;
        self.x = x * rad.cos() + z * rad.sin();
        self.z = -x * rad.sin() + z * rad.cos();
    }

    fn rotate_z(&mut self, angle: f64) {
        let rad = angle.to_radians();
        let x = self.x;
        let y = self.y;
        self.x = x * rad.cos() - y * rad.sin();
        self.y = x * rad.sin() + y * rad.cos();
    }
}

struct TransformManager {
    point: Transform3D,
}

impl TransformManager {
    fn new(initial_point: (f64, f64, f64)) -> Self {
        TransformManager {
            point: Transform3D::new(initial_point.0, initial_point.1, initial_point.2),
        }
    }

    fn apply_transforms(&mut self, translations: &[(f64, f64, f64)], rotations: &[(&str, f64)]) {
        for (dx, dy, dz) in translations {
            self.point.translate(*dx, *dy, *dz);
        }
        for (axis, angle) in rotations {
            match *axis {
                "x" => self.point.rotate_x(*angle),
                "y" => self.point.rotate_y(*angle),
                "z" => self.point.rotate_z(*angle),
                _ => {}
            }
        }
    }

    fn get_current_position(&self) -> (f64, f64, f64) {
        (self.point.x, self.point.y, self.point.z)
    }
}

fn main() {
    let initial_point = (0.0, 0.0, 0.0);
    let mut manager = TransformManager::new(initial_point);
    let translations = vec![(1.0, 2.0, 3.0), (4.0, 5.0, 6.0), (7.0, 8.0, 9.0)];
    let rotations = vec![("x", 90.0), ("y", 45.0), ("z", 30.0)];
    loop {
        manager.apply_transforms(&translations, &rotations);
        let current_position = manager.get_current_position();
        println!("{:?}", current_position);
    }
}