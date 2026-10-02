fn f() -> impl Iterator<Item = i32> {
    let mut a = 0;
    let mut b = 1;
    std::iter::from_fn(move || {
        let next = a;
        a = b;
        b = next + b;
        Some(next)
    })
}

fn g() -> impl Iterator<Item = i32> {
    f().map(|x| x % 2)
}

fn main() {
    let h = g();
    loop {
        println!("{}", h.next().unwrap());
    }
}