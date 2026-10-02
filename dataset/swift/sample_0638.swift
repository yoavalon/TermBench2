func transform_3d(x: Int, y: Int, z: Int, n: Int) -> (Int, Int, Int) {
    if n == 0 {
        return (x, y, z)
    }
    return transform_3d(x: y, y: z, z: x, n: n - 1)
}

let result = transform_3d(x: 1, y: 2, z: 3, n: 5)