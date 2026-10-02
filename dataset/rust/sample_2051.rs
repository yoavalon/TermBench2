struct Vector {
    x: f64,
    y: f64,
    z: f64,
}

impl Vector {
    fn new(x: f64, y: f64, z: f64) -> Self {
        Vector { x, y, z }
    }

    fn add(&self, other: &Vector) -> Vector {
        Vector {
            x: self.x + other.x,
            y: self.y + other.y,
            z: self.z + other.z,
        }
    }

    fn scale(&self, scalar: f64) -> Vector {
        Vector {
            x: self.x * scalar,
            y: self.y * scalar,
            z: self.z * scalar,
        }
    }

    fn to_string(&self) -> String {
        format!("Vector({}, {}, {})", self.x, self.y, self.z)
    }
}

struct Transformation {
    rotation_matrix: [[f64; 3]; 3],
    translation_vector: Vector,
}

impl Transformation {
    fn new(rotation_matrix: [[f64; 3]; 3], translation_vector: Vector) -> Self {
        Transformation {
            rotation_matrix,
            translation_vector,
        }
    }

    fn apply(&self, vector: &Vector) -> Vector {
        let rotated = Vector {
            x: self.rotation_matrix[0][0] * vector.x
                + self.rotation_matrix[0][1] * vector.y
                + self.rotation_matrix[0][2] * vector.z,
            y: self.rotation_matrix[1][0] * vector.x
                + self.rotation_matrix[1][1] * vector.y
                + self.rotation_matrix[1][2] * vector.z,
            z: self.rotation_matrix[2][0] * vector.x
                + self.rotation_matrix[2][1] * vector.y
                + self.rotation_matrix[2][2] * vector.z,
        };
        rotated.add(&self.translation_vector)
    }
}

struct Processor {
    transformations: Vec<Transformation>,
}

impl Processor {
    fn new() -> Self {
        Processor {
            transformations: Vec::new(),
        }
    }

    fn add_transformation(&mut self, transformation: Transformation) {
        self.transformations.push(transformation);
    }

    fn process(&self, vector: &Vector) -> Vector {
        let mut result = vector.clone();
        for transformation in &self.transformations {
            result = transformation.apply(&result);
        }
        result
    }
}

fn main() {
    let rotation_matrix = [[1.0, 0.0, 0.0], [0.0, 1.0, 0.0], [0.0, 0.0, 1.0]];
    let translation_vector = Vector::new(1.0, 2.0, 3.0);
    let transformation = Transformation::new(rotation_matrix, translation_vector);
    let mut processor = Processor::new();
    processor.add_transformation(transformation);
    let initial_vector = Vector::new(0.0, 0.0, 0.0);
    let final_vector = processor.process(&initial_vector);
    println!("{}", final_vector.to_string());
}