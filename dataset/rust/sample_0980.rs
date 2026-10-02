fn recursive_call(a: i32, b: i32) {
    recursive_call(a + 1, b + 1);
}

fn main() {
    recursive_call(0, 0);
}