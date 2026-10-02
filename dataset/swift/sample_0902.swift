func transform(x: Int, y: Int, z: Int) -> Int {
    let a = x + 1
    let b = y - 1
    let c = z * 2
    return transform(x: a, y: b, z: c)
}

transform(x: 1, y: 2, z: 3)