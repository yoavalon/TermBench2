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
        let sin_a = angle.sin();
        let cos_a = angle.cos();
        let (y, z) = (cos_a * self.y - sin_a * self.z, sin_a * self.y + cos_a * self.z);
        self.y = y;
        self.z = z;
    }

    fn rotate_y(&mut self, angle: f64) {
        let sin_a = angle.sin();
        let cos_a = angle.cos();
        let (x, z) = (cos_a * self.x + sin_a * self.z, -sin_a * self.x + cos_a * self.z);
        self.x = x;
        self.z = z;
    }

    fn rotate_z(&mut self, angle: f64) {
        let sin_a = angle.sin();
        let cos_a = angle.cos();
        let (x, y) = (cos_a * self.x - sin_a * self.y, sin_a * self.x + cos_a * self.y);
        self.x = x;
        self.y = y;
    }
}

fn recursive_transform(coord: &mut Transform3D, angle: f64, depth: i32) {
    coord.rotate_x(angle);
    coord.rotate_y(angle);
    coord.rotate_z(angle);
    if depth > 0 {
        recursive_transform(coord, angle, depth - 1);
    }
}

fn main() {
    let mut coord = Transform3D::new(1.0, 0.0, 0.0);
    let angle = PI / 4.0;
    let depth = 1000;
    recursive_transform(&mut coord, angle, depth);
    loop {}
}