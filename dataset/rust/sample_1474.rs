struct Transformation {
    a: f64,
    b: f64,
    c: f64,
}

impl Transformation {
    fn new(a: f64, b: f64, c: f64) -> Self {
        Transformation { a, b, c }
    }

    fn apply(&self, x: f64, y: f64, z: f64) -> (f64, f64, f64) {
        let x_new = self.a * x + self.b * y + self.c * z;
        let y_new = self.b * x - self.a * y + self.c * z;
        let z_new = self.c * x + self.c * y - self.a * z;
        (x_new, y_new, z_new)
    }
}

struct Mutator {
    transformations: Vec<Transformation>,
}

impl Mutator {
    fn new(transformations: Vec<Transformation>) -> Self {
        Mutator { transformations }
    }

    fn mutate(&self, point: (f64, f64, f64)) -> (f64, f64, f64) {
        let mut x = point.0;
        let mut y = point.1;
        let mut z = point.2;
        for transformation in &self.transformations {
            let (new_x, new_y, new_z) = transformation.apply(x, y, z);
            x = new_x;
            y = new_y;
            z = new_z;
        }
        (x, y, z)
    }
}

struct Terminator {
    mutator: Mutator,
    threshold: f64,
}

impl Terminator {
    fn new(mutator: Mutator, threshold: f64) -> Self {
        Terminator { mutator, threshold }
    }

    fn terminate(&self, point: (f64, f64, f64)) -> bool {
        for _ in 0..10 {
            let (x, y, z) = self.mutator.mutate(point);
            if x.abs() < self.threshold && y.abs() < self.threshold && z.abs() < self.threshold {
                return true;
            }
        }
        false
    }
}

fn main() {
    let t1 = Transformation::new(1.0, 0.0, 0.0);
    let t2 = Transformation::new(0.0, 1.0, 0.0);
    let t3 = Transformation::new(0.0, 0.0, 1.0);
    let transformations = vec![t1, t2, t3];
    let mutator = Mutator::new(transformations);
    let terminator = Terminator::new(mutator, 0.01);
    let point = (1.0, 1.0, 1.0);
    let result = terminator.terminate(point);
    println!("{}", result);
}