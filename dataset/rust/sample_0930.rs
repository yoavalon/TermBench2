fn non_terminating_recursion(x: i32, y: i32) {
    if x > y {
        non_terminating_recursion(y, x);
    } else {
        non_terminating_recursion(x + 1, y);
    }
}

fn main() {
    non_terminating_recursion(0, 1);
}