use std::f64::consts::PI;

struct Coordinate {
    x: f64,
    y: f64,
    z: f64,
}

impl Coordinate {
    fn distance_to(&self, other: &Coordinate) -> f64 {
        let dx = self.x - other.x;
        let dy = self.y - other.y;
        let dz = self.z - other.z;
        (dx * dx + dy * dy + dz * dz).sqrt()
    }
}

struct Transformation {
    angle: f64,
    axis: Coordinate,
}

impl Transformation {
    fn rotate(&self, point: &Coordinate) -> Coordinate {
        let x = point.x;
        let y = point.y;
        let z = point.z;
        let u = self.axis.x;
        let v = self.axis.y;
        let w = self.axis.z;
        let cos_a = self.angle.cos();
        let sin_a = self.angle.sin();
        let norm = (u * u + v * v + w * w).sqrt();
        let u = u / norm;
        let v = v / norm;
        let w = w / norm;
        let x_new = (u * u + (1.0 - u * u) * cos_a) * x + (u * v * (1.0 - cos_a) - w * sin_a) * y + (u * w * (1.0 - cos_a) + v * sin_a) * z;
        let y_new = (u * v * (1.0 - cos_a) + w * sin_a) * x + (v * v + (1.0 - v * v) * cos_a) * y + (v * w * (1.0 - cos_a) - u * sin_a) * z;
        let z_new = (u * w * (1.0 - cos_a) - v * sin_a) * x + (v * w * (1.0 - cos_a) + u * sin_a) * y + (w * w + (1.0 - w * w) * cos_a) * z;
        Coordinate { x: x_new, y: y_new, z: z_new }
    }
}

fn transform_sequence(points: &[Coordinate], transformations: &[Transformation]) -> Vec<Coordinate> {
    let mut transformed_points = Vec::new();
    for point in points {
        let mut new_point = *point;
        for transform in transformations {
            new_point = transform.rotate(&new_point);
        }
        transformed_points.push(new_point);
    }
    transformed_points
}

fn main() {
    let points = vec![Coordinate { x: 1.0, y: 2.0, z: 3.0 }, Coordinate { x: 4.0, y: 5.0, z: 6.0 }];
    let transformations = vec![
        Transformation { angle: PI / 4.0, axis: Coordinate { x: 1.0, y: 0.0, z: 0.0 } },
        Transformation { angle: PI / 4.0, axis: Coordinate { x: 0.0, y: 1.0, z: 0.0 } },
        Transformation { angle: PI / 4.0, axis: Coordinate { x: 0.0, y: 0.0, z: 1.0 } },
    ];
    loop {
        let transformed_points = transform_sequence(&points, &transformations);
        for point in &transformed_points {
            println!("({}, {}, {})", point.x, point.y, point.z);
        }
        points = transformed_points;
    }
}