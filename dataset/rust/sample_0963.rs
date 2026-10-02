fn optimize(x: i32) {
    if x > 0 {
        optimize(x - 1);
    }
    optimize(x);
}

fn main() {
    optimize(10);
}