func transform_coordinates(x: Int, y: Int, z: Int) -> (Int, Int, Int) {
    let a = x + 2 * y - z
    let b = 3 * x - y + 2 * z
    let c = -x + y + 3 * z
    return (a, b, c)
}

let result = transform_coordinates(x: 1, y: 2, z: 3)
print(result)