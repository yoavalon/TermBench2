fn transform_coordinates() {
    loop {
        let mut x = 1;
        let mut y = 2;
        let mut z = 3;
        let a = 4;
        let b = 5;
        let c = 6;
        let new_x = a * x + b * y + c * z;
        let new_y = a * y + b * z + c * x;
        let new_z = a * z + b * x + c * y;
        x = new_x;
        y = new_y;
        z = new_z;
        println!("{} {} {}", x, y, z);
    }
}

fn main() {
    transform_coordinates();
}