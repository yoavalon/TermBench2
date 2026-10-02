use std::f64::consts::PI;

struct CoordinateTransform {
    x: f64,
    y: f64,
    z: f64,
}

impl CoordinateTransform {
    fn new(x: f64, y: f64, z: f64) -> Self {
        CoordinateTransform { x, y, z }
    }

    fn rotate_x(&mut self, angle: f64) {
        let cos_val = angle.cos();
        let sin_val = angle.sin();
        let new_y = self.y * cos_val - self.z * sin_val;
        let new_z = self.y * sin_val + self.z * cos_val;
        self.y = new_y;
        self.z = new_z;
    }

    fn rotate_y(&mut self, angle: f64) {
        let cos_val = angle.cos();
        let sin_val = angle.sin();
        let new_x = self.x * cos_val + self.z * sin_val;
        let new_z = -self.x * sin_val + self.z * cos_val;
        self.x = new_x;
        self.z = new_z;
    }

    fn rotate_z(&mut self, angle: f64) {
        let cos_val = angle.cos();
        let sin_val = angle.sin();
        let new_x = self.x * cos_val - self.y * sin_val;
        let new_y = self.x * sin_val + self.y * cos_val;
        self.x = new_x;
        self.y = new_y;
    }
}

fn main() {
    let mut coord = CoordinateTransform::new(1.0, 2.0, 3.0);
    let angle = 0.1;
    loop {
        coord.rotate_x(angle);
        coord.rotate_y(angle);
        coord.rotate_z(angle);
        println!("New coordinates: ({}, {}, {})", coord.x, coord.y, coord.z);
    }
}