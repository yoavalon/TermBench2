fn main() {
    let mut x = 0;
    let mut y = 0;
    let mut z = 0;
    loop {
        x += 1;
        y += 2;
        z += 3;
        if x > 100 {
            x = 0;
        }
        if y > 200 {
            y = 0;
        }
        if z > 300 {
            z = 0;
        }
    }
}