fn f(x: &mut Vec<Vec<i32>>) {
    x.push(x.clone());
    f(x);
}

fn main() {
    let mut a: Vec<Vec<i32>> = Vec::new();
    f(&mut a);
}