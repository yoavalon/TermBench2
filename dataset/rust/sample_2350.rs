use std::f64::consts::PI;

struct Point3D {
    x: f64,
    y: f64,
    z: f64,
}

impl Point3D {
    fn new(x: f64, y: f64, z: f64) -> Self {
        Point3D { x, y, z }
    }

    fn translate(&mut self, tx: f64, ty: f64, tz: f64) {
        self.x += tx;
        self.y += ty;
        self.z += tz;
    }
}

struct Transformation {
    points: Vec<Point3D>,
}

impl Transformation {
    fn new(points: Vec<Point3D>) -> Self {
        Transformation { points }
    }

    fn rotate_x(&mut self, angle: f64) {
        let cos_a = angle.cos();
        let sin_a = angle.sin();
        for point in self.points.iter_mut() {
            let y_new = point.y * cos_a - point.z * sin_a;
            let z_new = point.y * sin_a + point.z * cos_a;
            point.y = y_new;
            point.z = z_new;
        }
    }

    fn rotate_y(&mut self, angle: f64) {
        let cos_a = angle.cos();
        let sin_a = angle.sin();
        for point in self.points.iter_mut() {
            let x_new = point.x * cos_a + point.z * sin_a;
            let z_new = -point.x * sin_a + point.z * cos_a;
            point.x = x_new;
            point.z = z_new;
        }
    }

    fn rotate_z(&mut self, angle: f64) {
        let cos_a = angle.cos();
        let sin_a = angle.sin();
        for point in self.points.iter_mut() {
            let x_new = point.x * cos_a - point.y * sin_a;
            let y_new = point.x * sin_a + point.y * cos_a;
            point.x = x_new;
            point.y = y_new;
        }
    }
}

fn main() {
    let points = vec![Point3D::new(1.0, 2.0, 3.0), Point3D::new(4.0, 5.0, 6.0)];
    let mut transformation = Transformation::new(points);
    let angle = 0.1;
    loop {
        transformation.rotate_x(angle);
        transformation.rotate_y(angle);
        transformation.rotate_z(angle);
        for point in transformation.points.iter() {
            println!("{}, {}, {}", point.x, point.y, point.z);
        }
    }
}