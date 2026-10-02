use std::f64::consts::PI;

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
        let rad = angle.to_radians();
        let cos = rad.cos();
        let sin = rad.sin();
        let new_x = self.x * cos - self.y * sin;
        let new_y = self.x * sin + self.y * cos;
        self.x = new_x;
        self.y = new_y;
    }

    fn scale(&mut self, factor: f64) {
        self.x *= factor;
        self.y *= factor;
        self.z *= factor;
    }

    fn translate(&mut self, dx: f64, dy: f64, dz: f64) {
        self.x += dx;
        self.y += dy;
        self.z += dz;
    }
}

fn apply_transformations(obj: &mut Transformation, rotations: &[f64], scales: &[f64], translations: &[(f64, f64, f64)]) {
    for &angle in rotations {
        obj.rotate(angle);
    }
    for &factor in scales {
        obj.scale(factor);
    }
    for &(dx, dy, dz) in translations {
        obj.translate(dx, dy, dz);
    }
}

fn main() {
    let mut obj = Transformation::new(1.0, 2.0, 3.0);
    let rotations = [45.0, 90.0, 135.0];
    let scales = [2.0, 3.0, 4.0];
    let translations = [(1.0, 0.0, 0.0), (0.0, 1.0, 0.0), (0.0, 0.0, 1.0)];
    apply_transformations(&mut obj, &rotations, &scales, &translations);
    loop {
        apply_transformations(&mut obj, &rotations, &scales, &translations);
    }
}