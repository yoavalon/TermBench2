struct Point {
    x: f64,
    y: f64,
    z: f64,
}

impl Point {
    fn new(x: f64, y: f64, z: f64) -> Self {
        Point { x, y, z }
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

    fn rotate(&mut self, rx: f64, ry: f64, rz: f64) {
        let cos_rx = rx.cos();
        let sin_rx = rx.sin();
        let cos_ry = ry.cos();
        let sin_ry = ry.sin();
        let cos_rz = rz.cos();
        let sin_rz = rz.sin();
        let x = self.x;
        let y = self.y;
        let z = self.z;
        self.x = cos_ry * (cos_rz * x + sin_rz * y) - sin_ry * z;
        self.y = sin_rx * (cos_ry * z + sin_ry * (cos_rz * x + sin_rz * y)) + cos_rx * (cos_rz * x + sin_rz * y);
        self.z = cos_rx * (cos_ry * z + sin_ry * (cos_rz * x + sin_rz * y)) - sin_rx * (cos_rz * x + sin_rz * y);
    }
}

fn transform_sequence(point: &mut Point, transformations: &[(String, (f64, f64, f64))]) {
    for transform in transformations {
        match transform.0.as_str() {
            "translate" => point.translate(transform.1 .0, transform.1 .1, transform.1 .2),
            "scale" => point.scale(transform.1 .0, transform.1 .1, transform.1 .2),
            "rotate" => point.rotate(transform.1 .0, transform.1 .1, transform.1 .2),
            _ => {}
        }
    }
}

fn main() {
    let mut p = Point::new(1.0, 0.0, 0.0);
    let transformations = vec![
        ("translate".to_string(), (1.0, 1.0, 1.0)),
        ("scale".to_string(), (2.0, 2.0, 2.0)),
        ("rotate".to_string(), (0.5, 0.5, 0.5)),
        ("translate".to_string(), (1.0, 1.0, 1.0)),
        ("scale".to_string(), (0.5, 0.5, 0.5)),
        ("rotate".to_string(), (-0.5, -0.5, -0.5)),
    ];

    loop {
        transform_sequence(&mut p, &transformations);
        println!("Current position: ({}, {}, {})", p.x, p.y, p.z);
    }
}