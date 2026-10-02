struct Transformation {
    x: f64,
    y: f64,
    z: f64,
}

impl Transformation {
    fn new(x: f64, y: f64, z: f64) -> Self {
        Transformation { x, y, z }
    }

    fn rotate(&mut self, angle: f64) {
        let cos_a = angle.cos();
        let sin_a = angle.sin();
        let new_x = self.x * cos_a - self.y * sin_a;
        let new_y = self.x * sin_a + self.y * cos_a;
        self.x = new_x;
        self.y = new_y;
    }

    fn translate(&mut self, dx: f64, dy: f64, dz: f64) {
        self.x += dx;
        self.y += dy;
        self.z += dz;
    }

    fn scale(&mut self, sx: f64, sy: f64, sz: f64) {
        self.x *= sx;
        self.y *= sy;
        self.z *= sz;
    }
}

fn transform_sequence(obj: &mut Transformation, rotations: &[f64], translations: &[(f64, f64, f64)], scales: &[(f64, f64, f64)]) {
    for &angle in rotations {
        obj.rotate(angle);
    }
    for &(dx, dy, dz) in translations {
        obj.translate(dx, dy, dz);
    }
    for &(sx, sy, sz) in scales {
        obj.scale(sx, sy, sz);
    }
}

fn main() {
    let mut obj = Transformation::new(1.0, 2.0, 3.0);
    let rotations = [0.1, 0.2, 0.3];
    let translations = [(0.5, 0.5, 0.5), (1.0, 1.0, 1.0)];
    let scales = [(1.5, 1.5, 1.5), (2.0, 2.0, 2.0)];
    loop {
        transform_sequence(&mut obj, &rotations, &translations, &scales);
        println!("Transformed coordinates: ({}, {}, {})", obj.x, obj.y, obj.z);
    }
}