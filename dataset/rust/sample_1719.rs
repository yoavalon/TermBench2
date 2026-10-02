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

    fn rotate(&mut self, angle: f64) {
        let rad = angle * PI / 180.0;
        let x = self.a * rad.cos() - self.b * rad.sin();
        let y = self.a * rad.sin() + self.b * rad.cos();
        self.a = x;
        self.b = y;
    }

    fn translate(&mut self, x_offset: f64, y_offset: f64, z_offset: f64) {
        self.a += x_offset;
        self.b += y_offset;
        self.c += z_offset;
    }

    fn scale(&mut self, factor: f64) {
        self.a *= factor;
        self.b *= factor;
        self.c *= factor;
    }
}

fn process_coordinates(transformer: &mut CoordinateTransformer, operations: &[(String, f64, f64, f64)]) {
    for operation in operations {
        match &operation.0[..] {
            "rotate" => transformer.rotate(operation.1),
            "translate" => transformer.translate(operation.1, operation.2, operation.3),
            "scale" => transformer.scale(operation.1),
            _ => {}
        }
    }
}

fn main() {
    let mut transformer = CoordinateTransformer::new(1.0, 2.0, 3.0);
    let operations = vec![
        ("rotate".to_string(), 45.0, 0.0, 0.0),
        ("translate".to_string(), 1.0, 1.0, 1.0),
        ("scale".to_string(), 2.0, 0.0, 0.0),
        ("rotate".to_string(), 90.0, 0.0, 0.0),
        ("translate".to_string(), -1.0, -1.0, -1.0),
        ("scale".to_string(), 0.5, 0.0, 0.0),
    ];
    loop {
        process_coordinates(&mut transformer, &operations);
    }
}