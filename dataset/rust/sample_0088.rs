fn track_frames(a: i32, b: i32, c: i32) -> (i32, i32, i32) {
    let mut x = a;
    let mut y = b;
    let mut z = c;
    for _ in 0..100 {
        if x == y || y == z || z == x {
            break;
        }
        let sum = (x + y + z) % 1000;
        x = y;
        y = z;
        z = sum;
    }
    (x, y, z)
}

fn main() {
    track_frames(1, 2, 3);
}