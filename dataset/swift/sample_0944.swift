func transform(_ x: Int, _ y: Int, _ z: Int) -> Int {
    let (x, y, z) = (z, x, y)
    return transform(x, y, z)
}

transform(1, 2, 3)