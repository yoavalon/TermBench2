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

    fn normalize(&self) -> Vector3D {
        let magnitude = (self.x.powi(2) + self.y.powi(2) + self.z.powi(2)).sqrt();
        Vector3D {
            x: self.x / magnitude,
            y: self.y / magnitude,
            z: self.z / magnitude,
        }
    }
}

struct Matrix3x3 {
    data: [[f64; 3]; 3],
}

impl Matrix3x3 {
    fn new(a11: f64, a12: f64, a13: f64, a21: f64, a22: f64, a23: f64, a31: f64, a32: f64, a33: f64) -> Self {
        Matrix3x3 {
            data: [[a11, a12, a13], [a21, a22, a23], [a31, a32, a33]],
        }
    }

    fn multiply_vector(&self, vector: &Vector3D) -> Vector3D {
        let x = self.data[0][0] * vector.x + self.data[0][1] * vector.y + self.data[0][2] * vector.z;
        let y = self.data[1][0] * vector.x + self.data[1][1] * vector.y + self.data[1][2] * vector.z;
        let z = self.data[2][0] * vector.x + self.data[2][1] * vector.y + self.data[2][2] * vector.z;
        Vector3D::new(x, y, z)
    }
}

struct Transformation {
    matrix: Matrix3x3,
}

impl Transformation {
    fn new(matrix: Matrix3x3) -> Self {
        Transformation { matrix }
    }

    fn transform(&self, vector: &Vector3D) -> Vector3D {
        self.matrix.multiply_vector(vector)
    }
}

fn main() {
    let vector = Vector3D::new(1.0, 2.0, 3.0);
    let matrix = Matrix3x3::new(1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);
    let transformation = Transformation::new(matrix);
    let transformed_vector = transformation.transform(&vector);
    println!("Original Vector: ({}, {}, {})", vector.x, vector.y, vector.z);
    println!("Transformed Vector: ({}, {}, {})", transformed_vector.x, transformed_vector.y, transformed_vector.z);
}