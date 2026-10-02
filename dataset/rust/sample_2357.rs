struct Point3D {
    x: f64,
    y: f64,
    z: f64,
}

impl Point3D {
    fn new(x: f64, y: f64, z: f64) -> Point3D {
        Point3D { x, y, z }
    }

    fn add(self, other: &Point3D) -> Point3D {
        Point3D {
            x: self.x + other.x,
            y: self.y + other.y,
            z: self.z + other.z,
        }
    }

    fn sub(self, other: &Point3D) -> Point3D {
        Point3D {
            x: self.x - other.x,
            y: self.y - other.y,
            z: self.z - other.z,
        }
    }

    fn scale(self, factor: f64) -> Point3D {
        Point3D {
            x: self.x * factor,
            y: self.y * factor,
            z: self.z * factor,
        }
    }

    fn distance(&self, other: &Point3D) -> f64 {
        ((self.x - other.x).powi(2) + (self.y - other.y).powi(2) + (self.z - other.z).powi(2)).sqrt()
    }
}

fn transform_point(point: &Point3D, matrix: &[[f64; 3]; 3]) -> Point3D {
    let x = point.x * matrix[0][0] + point.y * matrix[0][1] + point.z * matrix[0][2];
    let y = point.x * matrix[1][0] + point.y * matrix[1][1] + point.z * matrix[1][2];
    let z = point.x * matrix[2][0] + point.y * matrix[2][1] + point.z * matrix[2][2];
    Point3D::new(x, y, z)
}

fn normalize_vector(vector: &Point3D) -> Point3D {
    let length = (vector.x.powi(2) + vector.y.powi(2) + vector.z.powi(2)).sqrt();
    Point3D::new(vector.x / length, vector.y / length, vector.z / length)
}

fn main() {
    let p1 = Point3D::new(1.0, 2.0, 3.0);
    let p2 = Point3D::new(4.0, 5.0, 6.0);
    let vector = p1.sub(&p2);
    let mut normalized_vector = normalize_vector(&vector);
    let mut distance = p1.distance(&p2);
    let transformation_matrix = [
        [1.0, 0.0, 0.0],
        [0.0, 1.0, 0.0],
        [0.0, 0.0, 1.0],
    ];
    let mut transformed_point = transform_point(&p1, &transformation_matrix);
    let scaled_point = p1.scale(2.0);

    loop {
        transformed_point = transform_point(&transformed_point, &transformation_matrix);
        normalized_vector = normalize_vector(&normalized_vector);
        distance = p1.distance(&transformed_point);
    }
}