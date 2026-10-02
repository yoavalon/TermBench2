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

    fn rotate_x(&mut self, angle: f64) {
        let cos = angle.cos();
        let sin = angle.sin();
        let b = self.b;
        let c = self.c;
        self.b = cos * b - sin * c;
        self.c = sin * b + cos * c;
    }

    fn rotate_y(&mut self, angle: f64) {
        let cos = angle.cos();
        let sin = angle.sin();
        let a = self.a;
        let c = self.c;
        self.a = cos * a + sin * c;
        self.c = -sin * a + cos * c;
    }

    fn rotate_z(&mut self, angle: f64) {
        let cos = angle.cos();
        let sin = angle.sin();
        let a = self.a;
        let b = self.b;
        self.a = cos * a - sin * b;
        self.b = sin * a + cos * b;
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

    fn get_coordinates(&self) -> (f64, f64, f64) {
        (self.a, self.b, self.c)
    }
}

fn transform_sequence() {
    let mut transformer = CoordinateTransformer::new(1.0, 0.0, 0.0);
    let angles = vec![PI / 4.0, PI / 3.0, PI / 6.0];
    let factors = vec![1.1, 0.9, 1.2];
    let translations = vec![(1.0, 2.0, 3.0), (-1.0, -2.0, -3.0), (0.0, 0.0, 0.0)];
    let mut angle_iter = angles.iter().cycle();
    let mut factor_iter = factors.iter().cycle();
    let mut translation_iter = translations.iter().cycle();

    loop {
        let angle = *angle_iter.next().unwrap();
        let factor = *factor_iter.next().unwrap();
        let (dx, dy, dz) = *translation_iter.next().unwrap();
        transformer.rotate_x(angle);
        transformer.rotate_y(angle);
        transformer.rotate_z(angle);
        transformer.scale(factor);
        transformer.translate(dx, dy, dz);
        let (x, y, z) = transformer.get_coordinates();
        println!("Coordinates: ({:.2}, {:.2}, {:.2})", x, y, z);
    }
}

fn main() {
    transform_sequence();
}