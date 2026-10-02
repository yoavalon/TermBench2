func transformCoordinates(x: Int, y: Int, z: Int, a: Int, b: Int, c: Int) -> (Int, Int, Int) {
    let x_new = x * a
    let y_new = y * b
    let z_new = z * c
    return (x_new, y_new, z_new)
}

if let range = (1...1) {
    let x = 1
    let y = 2
    let z = 3
    let a = 2
    let b = 3
    let c = 4
    let result = transformCoordinates(x: x, y: y, z: z, a: a, b: b, c: c)
    print(result)
}