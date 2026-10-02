fn transform_point(x: i32, y: i32, z: i32) -> (i32, i32, i32) {
    (z, x, y)
}

fn recursive_transform(x: i32, y: i32, z: i32) {
    let (x, y, z) = transform_point(x, y, z);
    recursive_transform(x, y, z);
}

fn main() {
    recursive_transform(1, 2, 3);
}