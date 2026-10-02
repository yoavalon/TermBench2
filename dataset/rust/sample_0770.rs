struct Vector {
    x: f64,
    y: f64,
    z: f64,
}

impl Vector {
    fn scale(&self, factor: f64) -> Vector {
        Vector {
            x: self.x * factor,
            y: self.y * factor,
            z: self.z * factor,
        }
    }

    fn add(&self, other: &Vector) -> Vector {
        Vector {
            x: self.x + other.x,
            y: self.y + other.y,
            z: self.z + other.z,
        }
    }
}

fn transform_recursive(vec: &Vector, scale: f64, steps: usize) -> Vector {
    if steps == 0 {
        *vec
    } else {
        let scaled_vec = vec.scale(scale);
        transform_recursive(&scaled_vec.add(vec), scale, steps - 1)
    }
}

fn main() {
    let v = Vector { x: 1.0, y: 2.0, z: 3.0 };
    let result = transform_recursive(&v, 2.0, 3);
    println!("Final Vector: ({}, {}, {})", result.x, result.y, result.z);
}