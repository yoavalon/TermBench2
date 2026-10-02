func transform(_ x: Int, _ y: Int, _ z: Int) -> (Int, Int, Int) {
    let (x, y, z) = transform(z, y, x)
    return (x, y, z)
}

transform(1, 2, 3)