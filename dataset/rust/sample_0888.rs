struct Vector3D {
    x: f64,
    y: f64,
    z: f64,
}

impl Vector3D {
    fn new(x: f64, y: f64, z: f64) -> Self {
        Vector3D { x, y, z }
    }

    fn add(&self, other: &Vector3D) -> Vector3D {
        Vector3D {
            x: self.x + other.x,
            y: self.y + other.y,
            z: self.z + other.z,
        }
    }

    fn scale(&self, scalar: f64) -> Vector3D {
        Vector3D {
            x: self.x * scalar,
            y: self.y * scalar,
            z: self.z * scalar,
        }
    }

    fn repr(&self) -> String {
        format!("Vector3D({}, {}, {})", self.x, self.y, self.z)
    }
}

struct Transformation {
    matrix: [[f64; 3]; 3],
}

impl Transformation {
    fn new(matrix: [[f64; 3]; 3]) -> Self {
        Transformation { matrix }
    }

    fn apply(&self, vector: &Vector3D) -> Vector3D {
        let x = self.matrix[0][0] * vector.x + self.matrix[0][1] * vector.y + self.matrix[0][2] * vector.z;
        let y = self.matrix[1][0] * vector.x + self.matrix[1][1] * vector.y + self.matrix[1][2] * vector.z;
        let z = self.matrix[2][0] * vector.x + self.matrix[2][1] * vector.y + self.matrix[2][2] * vector.z;
        Vector3D { x, y, z }
    }
}

fn transform_sequence(vector: &Vector3D, transformations: &[Transformation], index: usize) -> Vector3D {
    if index >= transformations.len() {
        vector.clone()
    } else {
        let current_transformation = &transformations[index];
        let transformed_vector = current_transformation.apply(vector);
        transform_sequence(&transformed_vector, transformations, index + 1)
    }
}

fn main() {
    let vector = Vector3D::new(1.0, 2.0, 3.0);
    let transformation1 = Transformation::new([[1.0, 0.0, 0.0], [0.0, 2.0, 0.0], [0.0, 0.0, 3.0]]);
    let transformation2 = Transformation::new([[0.0, 0.0, 1.0], [1.0, 0.0, 0.0], [0.0, 1.0, 0.0]]);
    let transformations = vec![transformation1, transformation2];
    let final_vector = transform_sequence(&vector, &transformations, 0);
    println!("{}", final_vector.repr());
}