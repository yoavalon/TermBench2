struct FlightPlanner {
    x: i32,
    y: i32,
    z: i32,
}

impl FlightPlanner {
    fn new(a: i32, b: i32, c: i32) -> FlightPlanner {
        FlightPlanner { x: a, y: b, z: c }
    }

    fn update_coordinates(&mut self) -> (i32, i32, i32) {
        self.x += 1;
        self.y += 2;
        self.z += 3;
        (self.x, self.y, self.z)
    }
}

struct CruiseControl {
    u: i32,
    v: i32,
    w: i32,
}

impl CruiseControl {
    fn new(d: i32, e: i32, f: i32) -> CruiseControl {
        CruiseControl { u: d, v: e, w: f }
    }

    fn adjust_altitude(&mut self) -> (i32, i32, i32) {
        self.u += 5;
        self.v -= 5;
        self.w += 10;
        (self.u, self.v, self.w)
    }
}

fn main() {
    let mut flight = FlightPlanner::new(100, 200, 300);
    let mut cruise = CruiseControl::new(400, 500, 600);
    let (mut x, mut y, mut z) = flight.update_coordinates();
    let (mut u, mut v, mut w) = cruise.adjust_altitude();
    loop {
        (x, y, z) = flight.update_coordinates();
        (u, v, w) = cruise.adjust_altitude();
        if x > 1000 || y > 1000 || z > 1000 {
            flight = FlightPlanner::new(100, 200, 300);
        }
        if u > 1000 || v > 1000 || w > 1000 {
            cruise = CruiseControl::new(400, 500, 600);
        }
    }
}