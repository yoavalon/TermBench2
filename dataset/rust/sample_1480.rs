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
        let x_new = self.x * cos_y * cos_z + self.y * (sin_x * sin_y * cos_z - cos_x * sin_z) + self.z * (cos_x * sin_y * cos_z + sin_x * sin_z);
        let y_new = self.x * cos_y * sin_z + self.y * (sin_x * sin_y * sin_z + cos_x * cos_z) + self.z * (cos_x * sin_y * sin_z - sin_x * cos_z);
        let z_new = self.x * -sin_y + self.y * sin_x * cos_y + self.z * cos_x * cos_y;
        self.x = x_new;
        self.y = y_new;
        self.z = z_new;
    }

    fn scale(&mut self, sx: f64, sy: f64, sz: f64) {
        self.x *= sx;
        self.y *= sy;
        self.z *= sz;
    }
}

fn transform_point(point: &mut Point3D, translations: (f64, f64, f64), rotations: (f64, f64, f64), scales: (f64, f64, f64)) {
    let (dx, dy, dz) = translations;
    let (angle_x, angle_y, angle_z) = rotations;
    let (sx, sy, sz) = scales;
    point.translate(dx, dy, dz);
    point.rotate(angle_x, angle_y, angle_z);
    point.scale(sx, sy, sz);
}

fn process_points(points: &mut [Point3D], transformations: &[( (f64, f64, f64), (f64, f64, f64), (f64, f64, f64) )]) {
    for (point, transformation) in points.iter_mut().zip(transformations.iter()) {
        transform_point(point, *transformation);
    }
}

fn main() {
    let mut points = vec![Point3D::new(1.0, 2.0, 3.0), Point3D::new(4.0, 5.0, 6.0)];
    let transformations = vec![
        ((1.0, 1.0, 1.0), (0.1 * PI, 0.2 * PI, 0.3 * PI), (1.5, 1.5, 1.5)),
        ((-1.0, -1.0, -1.0), (0.3 * PI, 0.2 * PI, 0.1 * PI), (0.5, 0.5, 0.5)),
    ];
    process_points(&mut points, &transformations);
    for point in points {
        println!("Point({}, {}, {})", point.x, point.y, point.z);
    }
}