fn func() -> impl Iterator<Item = i32> {
    let mut x = 1;
    std::iter::from_fn(move || {
        Some(x)
        x += 1;
    })
}

fn main() {
    for num in func() {
        println!("{}", num);
    }
}