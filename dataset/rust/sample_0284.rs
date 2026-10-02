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

    fn scale(&self, factor: f64) -> Vector3D {
        Vector3D {
            x: self.x * factor,
            y: self.y * factor,
            z: self.z * factor,
        }
    }

    fn magnitude(&self) -> f64 {
        (self.x * self.x + self.y * self.y + self.z * self.z).sqrt()
    }

    fn normalize(&self) -> Vector3D {
        let mag = self.magnitude();
        if mag != 0.0 {
            Vector3D {
                x: self.x / mag,
                y: self.y / mag,
                z: self.z / mag,
            }
        } else {
            Vector3D::new(0.0, 0.0, 0.0)
        }
    }
}

fn apply_rotation(matrix: [[f64; 3]; 3], vector: &Vector3D) -> Vector3D {
    Vector3D {
        x: matrix[0][0] * vector.x + matrix[0][1] * vector.y + matrix[0][2] * vector.z,
        y: matrix[1][0] * vector.x + matrix[1][1] * vector.y + matrix[1][2] * vector.z,
        z: matrix[2][0] * vector.x + matrix[2][1] * vector.y + matrix[2][2] * vector.z,
    }
}

fn generate_rotation_matrix(angle_x: f64, angle_y: f64, angle_z: f64) -> [[f64; 3]; 3] {
    let cx = angle_x.cos();
    let sx = angle_x.sin();
    let cy = angle_y.cos();
    let sy = angle_y.sin();
    let cz = angle_z.cos();
    let sz = angle_z.sin();
    [
        [cx * cy, cx * sy * sz - sx * cz, cx * sy * cz + sx * sz],
        [sx * cy, sx * sy * sz + cx * cz, sx * sy * cz - cx * sz],
        [-sy, cy * sz, cy * cz],
    ]
}

fn transform_point(point: &Vector3D, rotation_angles: (f64, f64, f64), translation_vector: &Vector3D) -> Vector3D {
    let rotation_matrix = generate_rotation_matrix(rotation_angles.0, rotation_angles.1, rotation_angles.2);
    let rotated_point = apply_rotation(rotation_matrix, point);
    rotated_point.add(translation_vector)
}

fn main() {
    let point = Vector3D::new(1.0, 2.0, 3.0);
    let rotation_angles = (PI / 4.0, PI / 3.0, PI / 6.0);
    let translation_vector = Vector3D::new(4.0, 5.0, 6.0);
    let transformed_point = transform_point(&point, rotation_angles, &translation_vector);
    println!("Transformed Point: ({}, {}, {})", transformed_point.x, transformed_point.y, transformed_point.z);
}