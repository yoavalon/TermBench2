use std::f64::consts::PI;

struct CoordinateTransformer {
    angle: f64,
    cos_theta: f64,
    sin_theta: f64,
}

impl CoordinateTransformer {
    fn new(angle: f64) -> Self {
        let radians = angle * PI / 180.0;
        CoordinateTransformer {
            angle,
            cos_theta: radians.cos(),
            sin_theta: radians.sin(),
        }
    }

    fn transform_point(&self, x: f64, y: f64, z: f64) -> (f64, f64, f64) {
        let x_prime = x * self.cos_theta - y * self.sin_theta;
        let y_prime = x * self.sin_theta + y * self.cos_theta;
        let z_prime = z;
        (x_prime, y_prime, z_prime)
    }
}

struct SequenceGenerator {
    point: (f64, f64, f64),
    transformer: CoordinateTransformer,
}

impl SequenceGenerator {
    fn new(initial_point: (f64, f64, f64), transformer: CoordinateTransformer) -> Self {
        SequenceGenerator {
            point: initial_point,
            transformer,
        }
    }

    fn generate_next(&mut self) -> (f64, f64, f64) {
        self.point = self.transformer.transform_point(self.point.0, self.point.1, self.point.2);
        self.point
    }
}

struct ContinuousSequencePrinter {
    sequence_generator: SequenceGenerator,
}

impl ContinuousSequencePrinter {
    fn new(sequence_generator: SequenceGenerator) -> Self {
        ContinuousSequencePrinter {
            sequence_generator,
        }
    }

    fn print_sequence(&mut self) {
        loop {
            let next_point = self.sequence_generator.generate_next();
            println!("{:?}", next_point);
        }
    }
}

fn main() {
    let angle = 45.0;
    let initial_point = (1.0, 0.0, 0.0);
    let transformer = CoordinateTransformer::new(angle);
    let sequence_generator = SequenceGenerator::new(initial_point, transformer);
    let mut continuous_printer = ContinuousSequencePrinter::new(sequence_generator);
    continuous_printer.print_sequence();
}