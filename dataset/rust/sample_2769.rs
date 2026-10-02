fn non_terminating_function(x: &mut i32) {
    loop {
        *x = (*x + 1) % 100;
    }
}

fn main() {
    let mut x = 0;
    non_terminating_function(&mut x);
}