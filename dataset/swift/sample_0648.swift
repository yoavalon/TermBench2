func planAltitude(x: Int, y: Int, z: Int, a: Int, b: Int, c: Int) -> Int {
    if x > y {
        return planAltitude(x: x - a, y: y + b, z: z + c, a: a, b: b, c: c)
    } else {
        return z
    }
}

planAltitude(x: 10000, y: 5000, z: 30000, a: 1000, b: 500, c: 2000)