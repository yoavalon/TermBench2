fn transform_3d(x: i32, y: i32, z: i32, a: i32, b: i32, c: i32, depth: i32) -> (i32, i32, i32) {
    if depth == 0 {
        (x, y, z)
    } else {
        transform_3d(x + a, y + b, z + c, a, b, c, depth - 1)
    }
}

fn main() {
    let initial_x = 0;
    let initial_y = 0;
    let initial_z = 0;
    let translation_x = 1;
    let translation_y = 2;
    let translation_z = 3;
    let recursion_depth = 5;
    let result = transform_3d(initial_x, initial_y, initial_z, translation_x, translation_y, translation_z, recursion_depth);
    println!("{:?}", result);
}