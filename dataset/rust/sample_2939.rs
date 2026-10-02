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

    fn rotate_x(&mut self, angle: f64) {
        let angle_rad = angle.to_radians();
        let cos_val = angle_rad.cos();
        let sin_val = angle_rad.sin();
        let new_y = self.y * cos_val - self.z * sin_val;
        let new_z = self.y * sin_val + self.z * cos_val;
        self.y = new_y;
        self.z = new_z;
    }

    fn rotate_y(&mut self, angle: f64) {
        let angle_rad = angle.to_radians();
        let cos_val = angle_rad.cos();
        let sin_val = angle_rad.sin();
        let new_x = self.x * cos_val + self.z * sin_val;
        let new_z = -self.x * sin_val + self.z * cos_val;
        self.x = new_x;
        self.z = new_z;
    }

    fn rotate_z(&mut self, angle: f64) {
        let angle_rad = angle.to_radians();
        let cos_val = angle_rad.cos();
        let sin_val = angle_rad.sin();
        let new_x = self.x * cos_val - self.y * sin_val;
        let new_y = self.x * sin_val + self.y * cos_val;
        self.x = new_x;
        self.y = new_y;
    }
}

fn generate_sequence(start: (f64, f64, f64), increment: (f64, f64, f64), length: usize) -> Vec<Coordinate> {
    let mut sequence = Vec::new();
    let mut current = start;
    for _ in 0..length {
        sequence.push(Coordinate::new(current.0, current.1, current.2));
        current = (current.0 + increment.0, current.1 + increment.1, current.2 + increment.2);
    }
    sequence
}

fn apply_transformation(sequence: &mut [Coordinate], angle_x: f64, angle_y: f64, angle_z: f64) {
    for coord in sequence.iter_mut() {
        coord.rotate_x(angle_x);
        coord.rotate_y(angle_y);
        coord.rotate_z(angle_z);
    }
}

fn main() {
    let start_point = (0.0, 0.0, 0.0);
    let increment = (1.0, 1.0, 1.0);
    let sequence_length = 100;
    let mut sequence = generate_sequence(start_point, increment, sequence_length);
    let mut angle_x = 5.0;
    let mut angle_y = 5.0;
    let mut angle_z = 5.0;
    loop {
        apply_transformation(&mut sequence, angle_x, angle_y, angle_z);
        angle_x += 1.0;
        angle_y += 1.0;
        angle_z += 1.0;
    }
}