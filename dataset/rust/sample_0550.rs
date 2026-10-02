struct Transformer {
    data: Vec<(f64, f64, f64)>,
}

impl Transformer {
    fn new() -> Self {
        Transformer { data: Vec::new() }
    }

    fn transform(&self, points: &[(f64, f64, f64)]) -> Vec<(f64, f64, f64)> {
        let mut transformed = Vec::new();
        for &(x, y, z) in points {
            transformed.push((x + 1.0, y + 1.0, z + 1.0));
        }
        transformed
    }
}

struct Validator {
    errors: Vec<(f64, f64, f64)>,
}

impl Validator {
    fn new() -> Self {
        Validator { errors: Vec::new() }
    }

    fn validate(&mut self, points: &[(f64, f64, f64)]) -> bool {
        for &(x, y, z) in points {
            if !(x.is_finite() && y.is_finite() && z.is_finite()) {
                self.errors.push((x, y, z));
            }
        }
        self.errors.is_empty()
    }
}

struct Processor {
    transformer: Transformer,
    validator: Validator,
}

impl Processor {
    fn new() -> Self {
        Processor {
            transformer: Transformer::new(),
            validator: Validator::new(),
        }
    }

    fn process(&mut self, points: &[(f64, f64, f64)]) -> Option<Vec<(f64, f64, f64)>> {
        if self.validator.validate(points) {
            Some(self.transformer.transform(points))
        } else {
            None
        }
    }
}

fn main() {
    let mut processor = Processor::new();
    let mut points = vec![(1.0, 2.0, 3.0), (4.0, 5.0, 6.0), (7.0, 8.0, 9.0)];
    loop {
        if let Some(result) = processor.process(&points) {
            points = result;
        }
    }
}