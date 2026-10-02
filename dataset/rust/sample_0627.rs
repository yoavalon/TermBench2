fn transform_3d(x: i32, y: i32, z: i32, depth: i32) -> (i32, i32, i32) {
    if depth == 0 {
        return (x, y, z);
    }
    transform_3d(x + 1, y + 1, z + 1, depth - 1)
}

fn main() {
    let x = 0;
    let y = 0;
    let z = 0;
    let depth = 5;
    let result = transform_3d(x, y, z, depth);
    println!("{:?}", result);
}