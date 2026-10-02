fn f(a: i32, b: i32, c: i32) {
    let mut d = vec![(a, b, c)];
    loop {
        let e: Vec<(i32, i32, i32)> = d.iter().map(|&(x, y, z)| (x + y, y + z, z + x)).collect();
        d = e;
    }
}

fn main() {
    f(1, 1, 1);
}