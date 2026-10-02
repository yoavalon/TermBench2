use std::f64::consts::PI;

struct Point {
    x: f64,
    y: f64,
    z: f64,
}

impl Point {
    fn new(x: f64, y: f64, z: f64) -> Self {
        Point { x, y, z }
    }

    fn translate(&mut self, dx: f64, dy: f64, dz: f64) {
        self.x += dx;
        self.y += dy;
        self.z += dz;
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
        self.x = x * cos_y * cos_z + y * (-cos_x * sin_z + sin_x * sin_y * cos_z) + z * (sin_x * sin_z + cos_x * sin_y * cos_z);
        self.y = x * cos_y * sin_z + y * (cos_x * cos_z + sin_x * sin_y * sin_z) + z * (-sin_x * cos_z + cos_x * sin_y * sin_z);
        self.z = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y;
    }
}

fn transform_point(point: &mut Point, translation: (f64, f64, f64), rotation: (f64, f64, f64)) {
    point.translate(translation.0, translation.1, translation.2);
    point.rotate(rotation.0, rotation.1, rotation.2);
}

fn main() {
    let mut p = Point::new(1.0, 2.0, 3.0);
    let translation = (4.0, 5.0, 6.0);
    let rotation = (0.5, 1.0, 1.5);
    transform_point(&mut p, translation, rotation);
    println!("{} {} {}", p.x, p.y, p.z);
}