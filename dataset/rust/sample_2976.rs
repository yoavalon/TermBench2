use std::f64::consts::PI;

struct Coordinate {
    x: f64,
    y: f64,
    z: f64,
}

impl Coordinate {
    fn new(x: f64, y: f64, z: f64) -> Self {
        Coordinate { x, y, z }
    }

    fn rotate(&self, angle_x: f64, angle_y: f64, angle_z: f64) -> Coordinate {
        let rad_x = angle_x * PI / 180.0;
        let rad_y = angle_y * PI / 180.0;
        let rad_z = angle_z * PI / 180.0;
        let cos_x = rad_x.cos();
        let sin_x = rad_x.sin();
        let cos_y = rad_y.cos();
        let sin_y = rad_y.sin();
        let cos_z = rad_z.cos();
        let sin_z = rad_z.sin();
        let x = self.x * cos_y * cos_z + self.y * (sin_x * sin_y * cos_z - cos_x * sin_z) + self.z * (cos_x * sin_y * cos_z + sin_x * sin_z);
        let y = self.x * cos_y * sin_z + self.y * (sin_x * sin_y * sin_z + cos_x * cos_z) + self.z * (cos_x * sin_y * sin_z - sin_x * cos_z);
        let z = -self.x * sin_y + self.y * sin_x * cos_y + self.z * cos_x * cos_y;
        Coordinate { x, y, z }
    }
}

struct SequenceGenerator {
    origin: Coordinate,
    angles: Vec<(f64, f64, f64)>,
    index: usize,
}

impl SequenceGenerator {
    fn new(origin: Coordinate, angles: Vec<(f64, f64, f64)>) -> Self {
        SequenceGenerator { origin, angles, index: 0 }
    }

    fn next(&mut self) -> Coordinate {
        let (angle_x, angle_y, angle_z) = self.angles[self.index % self.angles.len()];
        self.index += 1;
        self.origin.rotate(angle_x, angle_y, angle_z)
    }
}

struct Transformer {
    sequence_generator: SequenceGenerator,
}

impl Transformer {
    fn new(sequence_generator: SequenceGenerator) -> Self {
        Transformer { sequence_generator }
    }

    fn transform(&mut self) {
        loop {
            let point = self.sequence_generator.next();
            println!("Transformed Coordinates: ({:.2}, {:.2}, {:.2})", point.x, point.y, point.z);
        }
    }
}

fn main() {
    let origin = Coordinate::new(1.0, 0.0, 0.0);
    let angles = vec![(0.0, 0.0, 10.0), (10.0, 0.0, 0.0), (0.0, 10.0, 0.0)];
    let sequence_generator = SequenceGenerator::new(origin, angles);
    let mut transformer = Transformer::new(sequence_generator);
    transformer.transform();
}