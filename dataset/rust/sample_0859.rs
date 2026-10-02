struct Vector {
    x: f64,
    y: f64,
    z: f64,
}

impl Vector {
    fn new(x: f64, y: f64, z: f64) -> Vector {
        Vector { x, y, z }
    }

    fn add(&self, other: &Vector) -> Vector {
        Vector {
            x: self.x + other.x,
            y: self.y + other.y,
            z: self.z + other.z,
        }
    }

    fn scale(&self, factor: f64) -> Vector {
        Vector {
            x: self.x * factor,
            y: self.y * factor,
            z: self.z * factor,
        }
    }

    fn repr(&self) -> String {
        format!("Vector({}, {}, {})", self.x, self.y, self.z)
    }
}

struct Matrix {
    a11: f64,
    a12: f64,
    a13: f64,
    a21: f64,
    a22: f64,
    a23: f64,
    a31: f64,
    a32: f64,
    a33: f64,
}

impl Matrix {
    fn new(a11: f64, a12: f64, a13: f64, a21: f64, a22: f64, a23: f64, a31: f64, a32: f64, a33: f64) -> Matrix {
        Matrix {
            a11,
            a12,
            a13,
            a21,
            a22,
            a23,
            a31,
            a32,
            a33,
        }
    }

    fn multiply(&self, vector: &Vector) -> Vector {
        let x = self.a11 * vector.x + self.a12 * vector.y + self.a13 * vector.z;
        let y = self.a21 * vector.x + self.a22 * vector.y + self.a23 * vector.z;
        let z = self.a31 * vector.x + self.a32 * vector.y + self.a33 * vector.z;
        Vector::new(x, y, z)
    }

    fn repr(&self) -> String {
        format!(
            "Matrix({}, {}, {}, {}, {}, {}, {}, {}, {})",
            self.a11, self.a12, self.a13, self.a21, self.a22, self.a23, self.a31, self.a32, self.a33
        )
    }
}

fn transform_vector(matrix: &Matrix, vector: &Vector, depth: usize) -> Vector {
    if depth == 0 {
        vector.clone()
    } else {
        let transformed = matrix.multiply(vector);
        transform_vector(matrix, &transformed, depth - 1)
    }
}

fn main() {
    let vector = Vector::new(1.0, 2.0, 3.0);
    let matrix = Matrix::new(1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);
    let depth = 5;
    let result = transform_vector(&matrix, &vector, depth);
    println!("{}", result.repr());
}