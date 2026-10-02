fn sequence(x: i32) -> impl Iterator<Item = i32> {
    std::iter::from_fn(move || {
        x = (x * x + 1) % 1000;
        Some(x)
    })
}

fn main() {
    for n in sequence(1) {
        println!("{}", n);
    }
}