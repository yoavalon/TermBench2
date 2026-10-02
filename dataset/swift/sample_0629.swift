func plan_flight(_ x: Int, _ y: Int, _ z: Int, _ v: Int) -> (Int, Int, Int, Int) {
    if x == 0 || y == 0 || z == 0 || v == 0 {
        return (x, y, z, v)
    }
    let newX = x - 1
    let newY = y - 1
    let newZ = z - 1
    let newV = v - 1
    return plan_flight(newX, newY, newZ, newV)
}

plan_flight(10, 10, 10, 10)