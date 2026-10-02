use std::f64::consts::PI;

struct Vector3D {
    x: f64,
    y: f64,
    z: f64,
}

impl Vector3D {
    fn new(x: f64, y: f64, z: f64) -> Self {
        Vector3D { x, y, z }
    }

    fn add(&self, other: &Self) -> Self {
        Vector3D {
            x: self.x + other.x,
            y: self.y + other.y,
            z: self.z + other.z,
        }
    }

    fn subtract(&self, other: &Self) -> Self {
        Vector3D {
            x: self.x - other.x,
            y: self.y - other.y,
            z: self.z - other.z,
        }
    }

    fn scale(&self, factor: f64) -> Self {
        Vector3D {
            x: self.x * factor,
            y: self.y * factor,
            z: self.z * factor,
        }
    }

    fn dot(&self, other: &Self) -> f64 {
        self.x * other.x + self.y * other.y + self.z * other.z
    }

    fn magnitude(&self) -> f64 {
        (self.x.powi(2) + self.y.powi(2) + self.z.powi(2)).sqrt()
    }

    fn normalize(&self) -> Self {
        let mag = self.magnitude();
        Vector3D {
            x: self.x / mag,
            y: self.y / mag,
            z: self.z / mag,
        }
    }
}

struct Matrix3D {
    data: [[f64; 3]; 3],
}

impl Matrix3D {
    fn new(a: f64, b: f64, c: f64, d: f64, e: f64, f: f64, g: f64, h: f64, i: f64) -> Self {
        Matrix3D {
            data: [[a, b, c], [d, e, f], [g, h, i]],
        }
    }

    fn multiply(&self, other: &Self) -> Self {
        let mut result = [[0.0; 3]; 3];
        for i in 0..3 {
            for j in 0..3 {
                let mut sum = 0.0;
                for k in 0..3 {
                    sum += self.data[i][k] * other.data[k][j];
                }
                result[i][j] = sum;
            }
        }
        Matrix3D::new(
            result[0][0], result[0][1], result[0][2],
            result[1][0], result[1][1], result[1][2],
            result[2][0], result[2][1], result[2][2],
        )
    }

    fn transform(&self, vector: &Vector3D) -> Vector3D {
        Vector3D {
            x: self.data[0][0] * vector.x + self.data[0][1] * vector.y + self.data[0][2] * vector.z,
            y: self.data[1][0] * vector.x + self.data[1][1] * vector.y + self.data[1][2] * vector.z,
            z: self.data[2][0] * vector.x + self.data[2][1] * vector.y + self.data[2][2] * vector.z,
        }
    }
}

fn rotation_matrix(axis: &str, theta: f64) -> Matrix3D {
    match axis {
        "x" => Matrix3D::new(1.0, 0.0, 0.0, 0.0, theta.cos(), -theta.sin(), 0.0, theta.sin(), theta.cos()),
        "y" => Matrix3D::new(theta.cos(), 0.0, theta.sin(), 0.0, 1.0, 0.0, -theta.sin(), 0.0, theta.cos()),
        "z" => Matrix3D::new(theta.cos(), -theta.sin(), 0.0, theta.sin(), theta.cos(), 0.0, 0.0, 0.0, 1.0),
        _ => panic!("Invalid axis"),
    }
}

fn main() {
    let v1 = Vector3D::new(1.0, 2.0, 3.0);
    let v2 = Vector3D::new(4.0, 5.0, 6.0);
    let v3 = v1.add(&v2);
    let v4 = v2.subtract(&v1);
    let v5 = v3.scale(2.0);
    let dot_product = v1.dot(&v2);
    let magnitude_v1 = v1.magnitude();
    let normalized_v1 = v1.normalize();
    let rot_x = rotation_matrix("x", PI / 4.0);
    let rot_y = rotation_matrix("y", PI / 4.0);
    let rot_z = rotation_matrix("z", PI / 4.0);
    let v6 = rot_x.transform(&v1);
    let v7 = rot_y.transform(&v1);
    let v8 = rot_z.transform(&v1);
    let matrix_product = rot_x.multiply(&rot_y);
    println!("{} {} {}", v3.x, v3.y, v3.z);
    println!("{} {} {}", v4.x, v4.y, v4.z);
    println!("{} {} {}", v5.x, v5.y, v5.z);
    println!("{}", dot_product);
    println!("{}", magnitude_v1);
    println!("{} {} {}", normalized_v1.x, normalized_v1.y, normalized_v1.z);
    println!("{} {} {}", v6.x, v6.y, v6.z);
    println!("{} {} {}", v7.x, v7.y, v7.z);
    println!("{} {} {}", v8.x, v8.y, v8.z);
    println!("{:?}", matrix_product.data);
}