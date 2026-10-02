fn main() {
    let mut x = 0;
    let mut y = 0;
    let mut z = 0;
    let mut v = 0;
    for _ in 0..100 {
        x += 1;
        y += 2;
        z += 3;
        v += 4;
    }
    println!("{} {} {} {}", x, y, z, v);
}