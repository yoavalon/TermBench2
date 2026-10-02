struct Vector3D {
    x: f64,
    y: f64,
    z: f64,
}

impl Vector3D {
    fn new(x: f64, y: f64, z: f64) -> Vector3D {
        Vector3D { x, y, z }
    }

    fn add(&self, other: &Vector3D) -> Vector3D {
        Vector3D {
            x: self.x + other.x,
            y: self.y + other.y,
            z: self.z + other.z,
        }
    }

    fn subtract(&self, other: &Vector3D) -> Vector3D {
        Vector3D {
            x: self.x - other.x,
            y: self.y - other.y,
            z: self.z - other.z,
        }
    }

    fn scale(&self, scalar: f64) -> Vector3D {
        Vector3D {
            x: self.x * scalar,
            y: self.y * scalar,
            z: self.z * scalar,
        }
    }

    fn magnitude(&self) -> f64 {
        (self.x.powi(2) + self.y.powi(2) + self.z.powi(2)).sqrt()
    }
}

struct Transformation {
    rotation_matrix: [[f64; 3]; 3],
    translation_vector: Vector3D,
}

impl Transformation {
    fn new(rotation_matrix: [[f64; 3]; 3], translation_vector: Vector3D) -> Transformation {
        Transformation {
            rotation_matrix,
            translation_vector,
        }
    }

    fn apply(&self, vector: &Vector3D) -> Vector3D {
        let x = vector.x * self.rotation_matrix[0][0]
            + vector.y * self.rotation_matrix[0][1]
            + vector.z * self.rotation_matrix[0][2];
        let y = vector.x * self.rotation_matrix[1][0]
            + vector.y * self.rotation_matrix[1][1]
            + vector.z * self.rotation_matrix[1][2];
        let z = vector.x * self.rotation_matrix[2][0]
            + vector.y * self.rotation_matrix[2][1]
            + vector.z * self.rotation_matrix[2][2];
        let translated_vector = Vector3D::new(x, y, z).add(&self.translation_vector);
        translated_vector
    }
}

fn generate_sequence(start: &Vector3D, transformation: &Transformation, steps: usize) -> Vec<Vector3D> {
    let mut sequence = Vec::new();
    let mut current_vector = start.clone();
    for _ in 0..steps {
        sequence.push(current_vector.clone());
        current_vector = transformation.apply(&current_vector);
    }
    sequence
}

fn main() {
    let start_vector = Vector3D::new(1.0, 0.0, 0.0);
    let rotation_matrix = [[0.0, -1.0, 0.0], [1.0, 0.0, 0.0], [0.0, 0.0, 1.0]];
    let translation_vector = Vector3D::new(1.0, 1.0, 1.0);
    let transformation = Transformation::new(rotation_matrix, translation_vector);
    let sequence = generate_sequence(&start_vector, &transformation, 10);
    for vector in sequence {
        println!("({}, {}, {})", vector.x, vector.y, vector.z);
    }
}