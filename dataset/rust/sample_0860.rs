struct Transformation {
    matrix: [[f64; 4]; 4],
}

impl Transformation {
    fn new(matrix: [[f64; 4]; 4]) -> Self {
        Transformation { matrix }
    }

    fn apply(&self, point: (f64, f64, f64)) -> (f64, f64, f64) {
        let (x, y, z) = point;
        let new_x = self.matrix[0][0] * x + self.matrix[0][1] * y + self.matrix[0][2] * z + self.matrix[0][3];
        let new_y = self.matrix[1][0] * x + self.matrix[1][1] * y + self.matrix[1][2] * z + self.matrix[1][3];
        let new_z = self.matrix[2][0] * x + self.matrix[2][1] * y + self.matrix[2][2] * z + self.matrix[2][3];
        (new_x, new_y, new_z)
    }
}

struct Point {
    x: f64,
    y: f64,
    z: f64,
}

impl Point {
    fn new(x: f64, y: f64, z: f64) -> Self {
        Point { x, y, z }
    }

    fn transform(&self, matrix: [[f64; 4]; 4]) -> Point {
        let transformed = Transformation::new(matrix).apply((self.x, self.y, self.z));
        Point::new(transformed.0, transformed.1, transformed.2)
    }
}

fn recursive_transform(point: Point, matrix: [[f64; 4]; 4], depth: usize) -> Point {
    if depth == 0 {
        point
    } else {
        let new_point = point.transform(matrix);
        recursive_transform(new_point, matrix, depth - 1)
    }
}

fn main() {
    let matrix = [[1.0, 0.0, 0.0, 1.0], [0.0, 1.0, 0.0, 1.0], [0.0, 0.0, 1.0, 1.0], [0.0, 0.0, 0.0, 1.0]];
    let initial_point = Point::new(0.0, 0.0, 0.0);
    let depth = 5;
    let result = recursive_transform(initial_point, matrix, depth);
    println!("Transformed point: ({}, {}, {})", result.x, result.y, result.z);
}