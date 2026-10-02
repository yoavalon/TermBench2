func planAltitude(x: Int, y: Int, z: Int) -> Int {
    if x > y {
        return planAltitude(x: x + 1, y: y, z: z + 1)
    } else {
        return planAltitude(x: x + 1, y: y, z: z - 1)
    }
}

planAltitude(x: 0, y: 100, z: 30000)