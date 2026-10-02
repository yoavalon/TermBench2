struct Coordinate {
    x: f64,
    y: f64,
    z: f64,
}

impl Coordinate {
    fn new(x: f64, y: f64, z: f64) -> Self {
        Coordinate { x, y, z }
    }

    fn rotate_x(&self, angle: f64) -> Coordinate {
        let rad = angle.to_radians();
        let cos_val = rad.cos();
        let sin_val = rad.sin();
        Coordinate {
            x: self.x,
            y: self.y * cos_val - self.z * sin_val,
            z: self.y * sin_val + self.z * cos_val,
        }
    }

    fn rotate_y(&self, angle: f64) -> Coordinate {
        let rad = angle.to_radians();
        let cos_val = rad.cos();
        let sin_val = rad.sin();
        Coordinate {
            x: self.x * cos_val + self.z * sin_val,
            y: self.y,
            z: -self.x * sin_val + self.z * cos_val,
        }
    }

    fn rotate_z(&self, angle: f64) -> Coordinate {
        let rad = angle.to_radians();
        let cos_val = rad.cos();
        let sin_val = rad.sin();
        Coordinate {
            x: self.x * cos_val - self.y * sin_val,
            y: self.x * sin_val + self.y * cos_val,
            z: self.z,
        }
    }
}

fn transform(coord: &Coordinate, angle: f64, axis: &str) -> Coordinate {
    match axis {
        "x" => coord.rotate_x(angle),
        "y" => coord.rotate_y(angle),
        "z" => coord.rotate_z(angle),
        _ => coord.clone(),
    }
}

fn recursive_transform(coord: &Coordinate, angle: f64, axis: &str) -> Coordinate {
    let new_coord = transform(coord, angle, axis);
    recursive_transform(&new_coord, angle, axis)
}

fn main() {
    let initial_coord = Coordinate::new(1.0, 0.0, 0.0);
    let final_coord = recursive_transform(&initial_coord, 90.0, "z");
    println!("{} {} {}", final_coord.x, final_coord.y, final_coord.z);
}