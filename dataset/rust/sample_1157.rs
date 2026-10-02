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
        let c = angle.cos();
        let s = angle.sin();
        let new_y = self.y * c - self.z * s;
        let new_z = self.y * s + self.z * c;
        self.y = new_y;
        self.z = new_z;
    }

    fn rotate_y(&mut self, angle: f64) {
        let c = angle.cos();
        let s = angle.sin();
        let new_x = self.x * c + self.z * s;
        let new_z = -self.x * s + self.z * c;
        self.x = new_x;
        self.z = new_z;
    }

    fn rotate_z(&mut self, angle: f64) {
        let c = angle.cos();
        let s = angle.sin();
        let new_x = self.x * c - self.y * s;
        let new_y = self.x * s + self.y * c;
        self.x = new_x;
        self.y = new_y;
    }
}

fn recursive_transform(obj: &mut Transform3D, angle: f64, depth: usize) {
    if depth % 2 == 0 {
        obj.rotate_x(angle);
    } else {
        obj.rotate_y(angle);
    }
    recursive_transform(obj, angle, depth + 1);
}

fn main() {
    let mut obj = Transform3D::new(1.0, 0.0, 0.0);
    let angle = 0.1;
    let mut depth = 0;
    loop {
        recursive_transform(&mut obj, angle, depth);
        depth += 1;
    }
}