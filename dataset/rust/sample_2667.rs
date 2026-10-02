use std::f64;

struct Point {
    x: f64,
    y: f64,
    z: f64,
}

impl Point {
    fn distance(&self, other: &Point) -> f64 {
        ((self.x - other.x).powi(2) + (self.y - other.y).powi(2) + (self.z - other.z).powi(2)).sqrt()
    }
}

struct Transformation {
    matrix: [[f64; 4]; 4],
}

impl Transformation {
    fn apply(&self, point: &Point) -> Point {
        Point {
            x: self.matrix[0][0] * point.x + self.matrix[0][1] * point.y + self.matrix[0][2] * point.z + self.matrix[0][3],
            y: self.matrix[1][0] * point.x + self.matrix[1][1] * point.y + self.matrix[1][2] * point.z + self.matrix[1][3],
            z: self.matrix[2][0] * point.x + self.matrix[2][1] * point.y + self.matrix[2][2] * point.z + self.matrix[2][3],
        }
    }
}

struct Sequence {
    start_point: Point,
    transformation: Transformation,
    steps: usize,
}

impl Sequence {
    fn generate(&self) -> Vec<Point> {
        let mut points = vec![self.start_point];
        let mut current = self.start_point;
        for _ in 0..self.steps {
            current = self.transformation.apply(&current);
            points.push(current);
        }
        points
    }
}

fn main() {
    let start = Point { x: 0.0, y: 0.0, z: 0.0 };
    let matrix = [
        [1.0, 0.0, 0.0, 1.0],
        [0.0, 1.0, 0.0, 1.0],
        [0.0, 0.0, 1.0, 1.0],
        [0.0, 0.0, 0.0, 1.0],
    ];
    let transform = Transformation { matrix };
    let seq = Sequence {
        start_point: start,
        transformation: transform,
        steps: 10,
    };
    let points = seq.generate();
    let distances: Vec<f64> = points.windows(2).map(|w| w[0].distance(&w[1])).collect();
    for distance in distances {
        println!("{}", distance);
    }
}