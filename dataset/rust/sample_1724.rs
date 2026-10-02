use std::f64::consts::PI;

struct Transformation {
    x: f64,
    y: f64,
    z: f64,
}

impl Transformation {
    fn new(x: f64, y: f64, z: f64) -> Self {
        Transformation { x, y, z }
    }

    fn rotate_x(&mut self, theta: f64) {
        let cos_t = theta.cos();
        let sin_t = theta.sin();
        let (y, z) = (self.y * cos_t - self.z * sin_t, self.y * sin_t + self.z * cos_t);
        self.y = y;
        self.z = z;
    }

    fn rotate_y(&mut self, theta: f64) {
        let cos_t = theta.cos();
        let sin_t = theta.sin();
        let (x, z) = (self.x * cos_t + self.z * sin_t, -self.x * sin_t + self.z * cos_t);
        self.x = x;
        self.z = z;
    }

    fn rotate_z(&mut self, theta: f64) {
        let cos_t = theta.cos();
        let sin_t = theta.sin();
        let (x, y) = (self.x * cos_t - self.y * sin_t, self.x * sin_t + self.y * cos_t);
        self.x = x;
        self.y = y;
    }
}

struct TransformationController {
    trans: Transformation,
    angles: [f64; 3],
}

impl TransformationController {
    fn new(trans: Transformation) -> Self {
        TransformationController {
            trans,
            angles: [0.05 * PI, 0.1 * PI, 0.15 * PI],
        }
    }

    fn execute_transformations(&mut self) {
        loop {
            for &angle in &self.angles {
                self.trans.rotate_x(angle);
                self.trans.rotate_y(angle);
                self.trans.rotate_z(angle);
            }
        }
    }
}

fn main() {
    let initial_x = 1.0;
    let initial_y = 2.0;
    let initial_z = 3.0;
    let mut transformation = Transformation::new(initial_x, initial_y, initial_z);
    let mut controller = TransformationController::new(transformation);
    controller.execute_transformations();
}