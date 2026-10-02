use std::f64::consts::PI;

struct Transformer {
    matrix: [[f64; 3]; 3],
}

impl Transformer {
    fn new() -> Self {
        Transformer {
            matrix: [[1.0, 0.0, 0.0], [0.0, 1.0, 0.0], [0.0, 0.0, 1.0]],
        }
    }

    fn apply_transformation(&self, point: (f64, f64, f64)) -> (f64, f64, f64) {
        let (x, y, z) = point;
        let new_x = self.matrix[0][0] * x + self.matrix[0][1] * y + self.matrix[0][2] * z;
        let new_y = self.matrix[1][0] * x + self.matrix[1][1] * y + self.matrix[1][2] * z;
        let new_z = self.matrix[2][0] * x + self.matrix[2][1] * y + self.matrix[2][2] * z;
        (new_x, new_y, new_z)
    }

    fn rotate_x(&mut self, angle: f64) {
        let cos_a = angle.cos();
        let sin_a = angle.sin();
        self.matrix = [[1.0, 0.0, 0.0], [0.0, cos_a, -sin_a], [0.0, sin_a, cos_a]];
    }

    fn rotate_y(&mut self, angle: f64) {
        let cos_a = angle.cos();
        let sin_a = angle.sin();
        self.matrix = [[cos_a, 0.0, sin_a], [0.0, 1.0, 0.0], [-sin_a, 0.0, cos_a]];
    }

    fn rotate_z(&mut self, angle: f64) {
        let cos_a = angle.cos();
        let sin_a = angle.sin();
        self.matrix = [[cos_a, -sin_a, 0.0], [sin_a, cos_a, 0.0], [0.0, 0.0, 1.0]];
    }
}

struct SequenceGenerator {
    transformer: Transformer,
    current_point: (f64, f64, f64),
}

impl SequenceGenerator {
    fn new(transformer: Transformer) -> Self {
        SequenceGenerator {
            transformer,
            current_point: (1.0, 0.0, 0.0),
        }
    }

    fn generate_sequence(&mut self) -> impl Iterator<Item = (f64, f64, f64)> {
        std::iter::from_fn(move || {
            let point = self.current_point;
            self.current_point = self.transformer.apply_transformation(point);
            Some(point)
        })
    }
}

fn main() {
    let mut transformer = Transformer::new();
    transformer.rotate_x(0.1);
    transformer.rotate_y(0.1);
    transformer.rotate_z(0.1);
    let mut generator = SequenceGenerator::new(transformer);
    for point in generator.generate_sequence() {
        println!("{:?}", point);
    }
}