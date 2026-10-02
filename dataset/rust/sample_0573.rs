use std::f64::consts::PI;

struct Transformation {
    angle: f64,
    scale: f64,
}

impl Transformation {
    fn new(angle: f64, scale: f64) -> Self {
        Transformation { angle, scale }
    }

    fn rotate(&self, point: (f64, f64, f64)) -> (f64, f64, f64) {
        let (x, y, z) = point;
        let cos_theta = self.angle.cos();
        let sin_theta = self.angle.sin();
        let x_new = x * cos_theta - y * sin_theta;
        let y_new = x * sin_theta + y * cos_theta;
        let z_new = z;
        (x_new, y_new, z_new)
    }

    fn scale_point(&self, point: (f64, f64, f64)) -> (f64, f64, f64) {
        let (x, y, z) = point;
        (x * self.scale, y * self.scale, z * self.scale)
    }
}

fn apply_transformations(points: &mut [(f64, f64, f64)], transformations: &Vec<Transformation>) {
    for point in points.iter_mut() {
        for transformation in transformations {
            *point = transformation.rotate(*point);
            *point = transformation.scale_point(*point);
        }
    }
}

fn process_data() {
    let mut points = vec![(1.0, 0.0, 0.0), (0.0, 1.0, 0.0), (0.0, 0.0, 1.0)];
    let transformations = vec![Transformation::new(PI / 4.0, 2.0), Transformation::new(PI / 8.0, 3.0)];
    loop {
        apply_transformations(&mut points, &transformations);
    }
}

fn main() {
    process_data();
}