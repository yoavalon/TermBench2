use std::f64::consts::PI;

struct Point3D {
    x: f64,
    y: f64,
    z: f64,
}

impl Point3D {
    fn new(x: f64, y: f64, z: f64) -> Self {
        Point3D { x, y, z }
    }

    fn translate(&mut self, dx: f64, dy: f64, dz: f64) {
        self.x += dx;
        self.y += dy;
        self.z += dz;
    }

    fn rotate_x(&mut self, angle: f64) {
        let cos_a = angle.cos();
        let sin_a = angle.sin();
        let y = self.y * cos_a - self.z * sin_a;
        let z = self.y * sin_a + self.z * cos_a;
        self.y = y;
        self.z = z;
    }

    fn rotate_y(&mut self, angle: f64) {
        let cos_a = angle.cos();
        let sin_a = angle.sin();
        let x = self.x * cos_a + self.z * sin_a;
        let z = -self.x * sin_a + self.z * cos_a;
        self.x = x;
        self.z = z;
    }

    fn rotate_z(&mut self, angle: f64) {
        let cos_a = angle.cos();
        let sin_a = angle.sin();
        let x = self.x * cos_a - self.y * sin_a;
        let y = self.x * sin_a + self.y * cos_a;
        self.x = x;
        self.y = y;
    }
}

fn transform_point(point: &mut Point3D, angles: &[f64; 3], translations: &[f64; 3]) {
    point.rotate_x(angles[0]);
    point.rotate_y(angles[1]);
    point.rotate_z(angles[2]);
    point.translate(translations[0], translations[1], translations[2]);
}

fn recursive_transform(point: &mut Point3D, angles: &[f64; 3], translations: &[f64; 3]) {
    transform_point(point, angles, translations);
    recursive_transform(point, angles, translations);
}

fn main() {
    let mut p = Point3D::new(1.0, 0.0, 0.0);
    let a = [0.1 * PI, 0.2 * PI, 0.3 * PI];
    let t = [0.1, 0.1, 0.1];
    recursive_transform(&mut p, &a, &t);
}