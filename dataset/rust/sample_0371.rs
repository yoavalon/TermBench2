fn optimize() {
    let mut x = 0;
    let mut y = 0;
    loop {
        x += 1;
        y += x;
        if y > 1000 {
            y = 0;
        }
    }
}

fn main() {
    optimize();
}