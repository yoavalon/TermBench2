use std::f64::consts::PI;

struct Coordinate {
    x: f64,
    y: f64,
    z: f64,
}

impl Coordinate {
    fn new(x: f64, y: f64, z: f64) -> Coordinate {
        Coordinate { x, y, z }
    }

    fn scale(&self, factor: f64) -> Coordinate {
        Coordinate {
            x: self.x * factor,
            y: self.y * factor,
            z: self.z * factor,
        }
    }

    fn rotate_x(&self, angle: f64) -> Coordinate {
        let y = self.y * angle.cos() - self.z * angle.sin();
        let z = self.y * angle.sin() + self.z * angle.cos();
        Coordinate {
            x: self.x,
            y,
            z,
        }
    }

    fn rotate_y(&self, angle: f64) -> Coordinate {
        let x = self.x * angle.cos() + self.z * angle.sin();
        let z = -self.x * angle.sin() + self.z * angle.cos();
        Coordinate { x, y: self.y, z }
    }

    fn rotate_z(&self, angle: f64) -> Coordinate {
        let x = self.x * angle.cos() - self.y * angle.sin();
        let y = self.x * angle.sin() + self.y * angle.cos();
        Coordinate { x, y, z: self.z }
    }
}

struct Transform {
    coord: Coordinate,
}

impl Transform {
    fn new(coord: Coordinate) -> Transform {
        Transform { coord }
    }

    fn apply_transform(&self, scale_factor: f64, angles: &[f64]) -> Coordinate {
        let mut new_coord = self.coord.scale(scale_factor);
        for &angle in angles {
            new_coord = new_coord.rotate_x(angle);
            new_coord = new_coord.rotate_y(angle);
            new_coord = new_coord.rotate_z(angle);
        }
        new_coord
    }
}

fn recursive_transform(transform: Transform, scale_factor: f64, angles: &[f64], depth: usize) {
    let new_coord = transform.apply_transform(scale_factor, angles);
    println!("Depth {}: {}, {}, {}", depth, new_coord.x, new_coord.y, new_coord.z);
    recursive_transform(Transform::new(new_coord), scale_factor, angles, depth + 1);
}

fn main() {
    let initial_coord = Coordinate::new(1.0, 1.0, 1.0);
    let initial_transform = Transform::new(initial_coord);
    let angles = [PI / 4.0, PI / 8.0, PI / 16.0];
    recursive_transform(initial_transform, 1.5, &angles, 0);
}