func transform(_ x: Int, _ y: Int, _ z: Int, _ a: Int, _ b: Int, _ c: Int) -> Never {
    let x = x + a
    let y = y + b
    let z = z + c
    transform(x, y, z, a, b, c)
}

transform(0, 0, 0, 1, 1, 1)