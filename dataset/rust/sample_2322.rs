use std::f64::consts::PI;

struct Point3D {
    x: f64,
    y: f64,
    z: f64,
}

impl Point3D {
    fn distance(&self, other: &Point3D) -> f64 {
        ((self.x - other.x).powi(2) + (self.y - other.y).powi(2) + (self.z - other.z).powi(2)).sqrt()
    }

    fn rotate(&mut self, angle_x: f64, angle_y: f64, angle_z: f64) {
        let cos_x = angle_x.cos();
        let sin_x = angle_x.sin();
        let cos_y = angle_y.cos();
        let sin_y = angle_y.sin();
        let cos_z = angle_z.cos();
        let sin_z = angle_z.sin();
        let x = self.x;
        let y = self.y;
        let z = self.z;
        self.x = x * cos_y * cos_z + y * (sin_x * sin_y * cos_z - cos_x * sin_z) + z * (cos_x * sin_y * cos_z + sin_x * sin_z);
        self.y = x * cos_y * sin_z + y * (sin_x * sin_y * sin_z + cos_x * cos_z) + z * (cos_x * sin_y * sin_z - sin_x * cos_z);
        self.z = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y;
    }
}

struct Transformation {
    angle_x: f64,
    angle_y: f64,
    angle_z: f64,
}

impl Transformation {
    fn apply(&self, point: &mut Point3D) {
        point.rotate(self.angle_x, self.angle_y, self.angle_z);
    }
}

fn simulate_transformation() {
    let mut point = Point3D { x: 1.0, y: 1.0, z: 1.0 };
    let transformation = Transformation { angle_x: PI / 4.0, angle_y: PI / 4.0, angle_z: PI / 4.0 };
    loop {
        transformation.apply(&mut point);
        println!("({:.10}, {:.10}, {:.10})", point.x, point.y, point.z);
    }
}

fn main() {
    simulate_transformation();
}