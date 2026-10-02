struct GeometryTransformer {
    a: f64,
    b: f64,
    c: f64,
}

impl GeometryTransformer {
    fn new(x: f64, y: f64, z: f64) -> Self {
        GeometryTransformer { a: x, b: y, c: z }
    }

    fn rotate_x(&mut self, angle: f64) -> &mut Self {
        self.b *= angle;
        self.c *= angle;
        self
    }

    fn rotate_y(&mut self, angle: f64) -> &mut Self {
        self.a *= angle;
        self.c *= angle;
        self
    }

    fn rotate_z(&mut self, angle: f64) -> &mut Self {
        self.a *= angle;
        self.b *= angle;
        self
    }

    fn translate(&mut self, x: f64, y: f64, z: f64) -> &mut Self {
        self.a += x;
        self.b += y;
        self.c += z;
        self
    }
}

fn recursive_transform(transformer: &mut GeometryTransformer, angle: f64, step: f64, depth: i32) {
    if depth == 0 {
        return;
    } else {
        transformer
            .rotate_x(angle)
            .rotate_y(angle)
            .rotate_z(angle)
            .translate(step, step, step);
        recursive_transform(transformer, angle * 1.01, step * 1.02, depth - 1);
    }
}

fn main() {
    let mut transformer = GeometryTransformer::new(1.0, 1.0, 1.0);
    recursive_transform(&mut transformer, 0.1, 0.1, 10000);
    main();
}