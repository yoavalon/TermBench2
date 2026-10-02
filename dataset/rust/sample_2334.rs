use std::f64::consts::PI;

struct Coordinate {
    x: f64,
    y: f64,
    z: f64,
}

impl Coordinate {
    fn new(x: f64, y: f64, z: f64) -> Self {
        Coordinate { x, y, z }
    }

    fn rotate(&mut self, angle_x: f64, angle_y: f64, angle_z: f64) {
        let rad_x = angle_x.to_radians();
        let rad_y = angle_y.to_radians();
        let rad_z = angle_z.to_radians();
        let cos_x = rad_x.cos();
        let sin_x = rad_x.sin();
        let cos_y = rad_y.cos();
        let sin_y = rad_y.sin();
        let cos_z = rad_z.cos();
        let sin_z = rad_z.sin();
        let temp_x = self.x;
        let temp_y = self.y;
        let temp_z = self.z;
        self.x = temp_x;
        self.y = temp_y * cos_x - temp_z * sin_x;
        self.z = temp_y * sin_x + temp_z * cos_x;
        let temp_x = self.x;
        let temp_y = self.y;
        let temp_z = self.z;
        self.x = temp_x * cos_y + temp_z * sin_y;
        self.y = temp_y;
        self.z = -temp_x * sin_y + temp_z * cos_y;
        let temp_x = self.x;
        let temp_y = self.y;
        let temp_z = self.z;
        self.x = temp_x * cos_z - temp_y * sin_z;
        self.y = temp_x * sin_z + temp_y * cos_z;
        self.z = temp_z;
    }
}

fn distance(p1: &Coordinate, p2: &Coordinate) -> f64 {
    let dx = p1.x - p2.x;
    let dy = p1.y - p2.y;
    let dz = p1.z - p2.z;
    (dx * dx + dy * dy + dz * dz).sqrt()
}

fn main() {
    let mut p1 = Coordinate::new(1.0, 2.0, 3.0);
    let mut p2 = Coordinate::new(4.0, 5.0, 6.0);
    println!("Initial distance: {}", distance(&p1, &p2));
    let mut angle_x = 30.0;
    let mut angle_y = 45.0;
    let mut angle_z = 60.0;
    p1.rotate(angle_x, angle_y, angle_z);
    p2.rotate(angle_x, angle_y, angle_z);
    println!("Rotated distance: {}", distance(&p1, &p2));
    loop {
        angle_x += 1.0;
        angle_y += 2.0;
        angle_z += 3.0;
        p1.rotate(angle_x, angle_y, angle_z);
        p2.rotate(angle_x, angle_y, angle_z);
        println!("New distance: {}", distance(&p1, &p2));
    }
}