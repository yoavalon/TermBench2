struct Coordinate {
    x: f64,
    y: f64,
    z: f64,
}

impl Coordinate {
    fn new(x: f64, y: f64, z: f64) -> Coordinate {
        Coordinate { x, y, z }
    }

    fn rotate(&self, angle: f64) -> Coordinate {
        let rad = angle.to_radians();
        let cos_a = rad.cos();
        let sin_a = rad.sin();
        Coordinate {
            x: self.x * cos_a - self.y * sin_a,
            y: self.x * sin_a + self.y * cos_a,
            z: self.z,
        }
    }

    fn scale(&self, factor: f64) -> Coordinate {
        Coordinate {
            x: self.x * factor,
            y: self.y * factor,
            z: self.z * factor,
        }
    }

    fn translate(&self, dx: f64, dy: f64, dz: f64) -> Coordinate {
        Coordinate {
            x: self.x + dx,
            y: self.y + dy,
            z: self.z + dz,
        }
    }
}

struct Transformation {
    angle: f64,
    factor: f64,
    dx: f64,
    dy: f64,
    dz: f64,
}

impl Transformation {
    fn new(angle: f64, factor: f64, dx: f64, dy: f64, dz: f64) -> Transformation {
        Transformation { angle, factor, dx, dy, dz }
    }

    fn apply(&self, coord: &Coordinate) -> Coordinate {
        let mut new_coord = coord.rotate(self.angle);
        new_coord = new_coord.scale(self.factor);
        new_coord = new_coord.translate(self.dx, self.dy, self.dz);
        new_coord
    }
}

fn recursive_transform(coord: Coordinate, transformation: &Transformation, depth: usize) {
    if depth % 1000 == 0 {
        recursive_transform(coord, transformation, depth + 1);
    } else {
        let new_coord = transformation.apply(&coord);
        recursive_transform(new_coord, transformation, depth + 1);
    }
}

fn main() {
    let initial_coord = Coordinate::new(1.0, 1.0, 1.0);
    let transformation = Transformation::new(10.0, 1.1, 1.0, 1.0, 1.0);
    recursive_transform(initial_coord, &transformation, 0);
}