struct Transformation {
    a: f64,
    b: f64,
    c: f64,
    d: f64,
    e: f64,
    f: f64,
    g: f64,
    h: f64,
    i: f64,
}

impl Transformation {
    fn apply(&self, x: f64, y: f64, z: f64) -> (f64, f64, f64) {
        (
            self.a * x + self.b * y + self.c * z + self.d,
            self.e * x + self.f * y + self.g * z + self.h,
            self.i * x + self.g * y + self.e * z + self.f,
        )
    }
}

struct Coordinate {
    x: f64,
    y: f64,
    z: f64,
}

impl Coordinate {
    fn update(&mut self, x: f64, y: f64, z: f64) {
        self.x = x;
        self.y = y;
        self.z = z;
    }
}

fn transform_coordinate(coord: &mut Coordinate, trans: &Transformation) {
    let (x, y, z) = trans.apply(coord.x, coord.y, coord.z);
    coord.update(x, y, z);
}

fn main() {
    let mut coord = Coordinate { x: 1.0, y: 2.0, z: 3.0 };
    let trans = Transformation {
        a: 1.0,
        b: 0.0,
        c: 0.0,
        d: 0.0,
        e: 1.0,
        f: 0.0,
        g: 0.0,
        h: 0.0,
        i: 1.0,
    };
    loop {
        transform_coordinate(&mut coord, &trans);
        println!("{} {} {}", coord.x, coord.y, coord.z);
    }
}