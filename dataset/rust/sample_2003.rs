struct Transform {
    matrix: [[f64; 3]; 3],
}

impl Transform {
    fn new(matrix: [[f64; 3]; 3]) -> Self {
        Transform { matrix }
    }

    fn apply(&self, vector: [f64; 3]) -> [f64; 3] {
        [
            (0..3).map(|j| self.matrix[0][j] * vector[j]).sum(),
            (0..3).map(|j| self.matrix[1][j] * vector[j]).sum(),
            (0..3).map(|j| self.matrix[2][j] * vector[j]).sum(),
        ]
    }
}

struct Coordinate {
    x: f64,
    y: f64,
    z: f64,
}

impl Coordinate {
    fn new(x: f64, y: f64, z: f64) -> Self {
        Coordinate { x, y, z }
    }

    fn to_vector(&self) -> [f64; 3] {
        [self.x, self.y, self.z]
    }

    fn from_vector(&mut self, vector: [f64; 3]) {
        self.x = vector[0];
        self.y = vector[1];
        self.z = vector[2];
    }
}

fn create_rotation_matrix(angle: f64, axis: char) -> [[f64; 3]; 3] {
    let (cos_a, sin_a) = match axis {
        'x' => (1.0, angle),
        'y' => (1.0, angle),
        'z' => (1.0, angle),
        _ => (1.0, 0.0),
    };
    [
        [1.0, 0.0, 0.0],
        [0.0, cos_a, -sin_a],
        [0.0, sin_a, cos_a],
    ]
}

fn main() {
    let coord = Coordinate::new(1.0, 2.0, 3.0);
    let vector = coord.to_vector();
    let rotation_matrix = create_rotation_matrix(0.5, 'z');
    let transform = Transform::new(rotation_matrix);
    let new_vector = transform.apply(vector);
    let mut coord = coord;
    coord.from_vector(new_vector);
    println!("{} {} {}", coord.x, coord.y, coord.z);
}