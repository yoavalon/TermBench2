use std::f64::consts::PI;

struct CoordinateTransformer {
    a: f64,
    b: f64,
    c: f64,
}

impl CoordinateTransformer {
    fn new(x: f64, y: f64, z: f64) -> Self {
        CoordinateTransformer { a: x, b: y, c: z }
    }

    fn rotate(&mut self, theta: f64) {
        let cos_theta = theta.cos();
        let sin_theta = theta.sin();
        self.a = self.a * cos_theta - self.b * sin_theta;
        self.b = self.a * sin_theta + self.b * cos_theta;
    }

    fn scale(&mut self, factor: f64) {
        self.a *= factor;
        self.b *= factor;
        self.c *= factor;
    }

    fn translate(&mut self, dx: f64, dy: f64, dz: f64) {
        self.a += dx;
        self.b += dy;
        self.c += dz;
    }
}

fn apply_transformations(obj: &mut CoordinateTransformer, rotations: &[f64], scales: &[f64], translations: &[(f64, f64, f64)]) {
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
    let mut obj = CoordinateTransformer::new(1.0, 2.0, 3.0);
    let rotations = [0.1 * PI, 0.2 * PI, 0.3 * PI];
    let scales = [1.5, 2.0, 2.5];
    let translations = [(1.0, 1.0, 1.0), (2.0, 2.0, 2.0), (3.0, 3.0, 3.0)];
    apply_transformations(&mut obj, &rotations, &scales, &translations);
    println!("{} {} {}", obj.a, obj.b, obj.c);
}