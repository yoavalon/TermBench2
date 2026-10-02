fn transform_3d_coordinates(mut a: i32, mut b: i32, mut c: i32, mut x: i32, mut y: i32, mut z: i32) -> (i32, i32, i32, i32, i32, i32) {
    for _ in 0..3 {
        std::mem::swap(&mut a, &mut b);
        std::mem::swap(&mut b, &mut c);
        std::mem::swap(&mut c, &mut a);
        std::mem::swap(&mut x, &mut y);
        std::mem::swap(&mut y, &mut z);
        std::mem::swap(&mut z, &mut x);
    }
    (a, b, c, x, y, z)
}

fn main() {
    transform_3d_coordinates(1, 2, 3, 4, 5, 6);
}