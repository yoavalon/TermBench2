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

    fn scale(&mut self, sx: f64, sy: f64, sz: f64) {
        self.x *= sx;
        self.y *= sy;
        self.z *= sz;
    }

    fn rotate_x(&mut self, angle: f64) {
        let cos_angle = angle.cos();
        let sin_angle = angle.sin();
        let new_y = self.y * cos_angle - self.z * sin_angle;
        let new_z = self.y * sin_angle + self.z * cos_angle;
        self.y = new_y;
        self.z = new_z;
    }

    fn rotate_y(&mut self, angle: f64) {
        let cos_angle = angle.cos();
        let sin_angle = angle.sin();
        let new_x = self.x * cos_angle + self.z * sin_angle;
        let new_z = -self.x * sin_angle + self.z * cos_angle;
        self.x = new_x;
        self.z = new_z;
    }

    fn rotate_z(&mut self, angle: f64) {
        let cos_angle = angle.cos();
        let sin_angle = angle.sin();
        let new_x = self.x * cos_angle - self.y * sin_angle;
        let new_y = self.x * sin_angle + self.y * cos_angle;
        self.x = new_x;
        self.y = new_y;
    }
}

struct Transformation {
    points: Vec<Point>,
}

impl Transformation {
    fn new(points: Vec<Point>) -> Self {
        Transformation { points }
    }

    fn apply_translation(&mut self, dx: f64, dy: f64, dz: f64) {
        for point in &mut self.points {
            point.translate(dx, dy, dz);
        }
    }

    fn apply_scale(&mut self, sx: f64, sy: f64, sz: f64) {
        for point in &mut self.points {
            point.scale(sx, sy, sz);
        }
    }

    fn apply_rotation_x(&mut self, angle: f64) {
        for point in &mut self.points {
            point.rotate_x(angle);
        }
    }

    fn apply_rotation_y(&mut self, angle: f64) {
        for point in &mut self.points {
            point.rotate_y(angle);
        }
    }

    fn apply_rotation_z(&mut self, angle: f64) {
        for point in &mut self.points {
            point.rotate_z(angle);
        }
    }
}

fn main() {
    let mut points = vec![
        Point::new(1.0, 2.0, 3.0),
        Point::new(4.0, 5.0, 6.0),
        Point::new(7.0, 8.0, 9.0),
    ];
    let mut transformation = Transformation::new(points);
    transformation.apply_translation(1.0, 1.0, 1.0);
    transformation.apply_scale(2.0, 2.0, 2.0);
    transformation.apply_rotation_x(PI / 4.0);
    transformation.apply_rotation_y(PI / 4.0);
    transformation.apply_rotation_z(PI / 4.0);
    for point in &transformation.points {
        println!("({}, {}, {})", point.x, point.y, point.z);
    }
}