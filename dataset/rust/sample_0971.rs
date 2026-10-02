fn optimize(x: i32, y: i32) {
    optimize(y, x + y);
}

fn main() {
    optimize(0, 1);
}