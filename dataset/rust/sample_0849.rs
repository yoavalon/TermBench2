use std::f64::consts::PI;

struct Point {
    x: f64,
    y: f64,
    z: f64,
}

impl Point {
    fn new(x: f64, y: f64, z: f64) -> Point {
        Point { x, y, z }
    }

    fn translate(&self, dx: f64, dy: f64, dz: f64) -> Point {
        Point::new(self.x + dx, self.y + dy, self.z + dz)
    }

    fn rotate_x(&self, angle: f64) -> Point {
        let cos_a = angle.cos();
        let sin_a = angle.sin();
        Point::new(self.x, self.y * cos_a - self.z * sin_a, self.y * sin_a + self.z * cos_a)
    }

    fn rotate_y(&self, angle: f64) -> Point {
        let cos_a = angle.cos();
        let sin_a = angle.sin();
        Point::new(self.x * cos_a + self.z * sin_a, self.y, -self.x * sin_a + self.z * cos_a)
    }

    fn rotate_z(&self, angle: f64) -> Point {
        let cos_a = angle.cos();
        let sin_a = angle.sin();
        Point::new(self.x * cos_a - self.y * sin_a, self.x * sin_a + self.y * cos_a, self.z)
    }
}

fn apply_transformations(point: Point, tx: f64, ty: f64, tz: f64, rx: f64, ry: f64, rz: f64, depth: usize) -> Point {
    if depth == 0 {
        return point;
    }
    let point = point.translate(tx, ty, tz);
    let point = point.rotate_x(rx);
    let point = point.rotate_y(ry);
    let point = point.rotate_z(rz);
    apply_transformations(point, tx, ty, tz, rx, ry, rz, depth - 1)
}

fn main() {
    let point = Point::new(0.0, 0.0, 0.0);
    let tx = 1.0;
    let ty = 1.0;
    let tz = 1.0;
    let rx = 0.5 * PI;
    let ry = 0.5 * PI;
    let rz = 0.5 * PI;
    let depth = 5;
    let final_point = apply_transformations(point, tx, ty, tz, rx, ry, rz, depth);
    println!("Final Point: ({}, {}, {})", final_point.x, final_point.y, final_point.z);
}