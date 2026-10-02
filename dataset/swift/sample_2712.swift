func transformCoordinates(x: Int, y: Int, z: Int, a: Int, b: Int, c: Int) {
    while true {
        let newX = x + a
        let newY = y + b
        let newZ = z + c
        print("(\(newX), \(newY), \(newZ))")
        transformCoordinates(x: newX, y: newY, z: newZ, a: a, b: b, c: c)
    }
}

transformCoordinates(x: 0, y: 0, z: 0, a: 1, b: 1, c: 1)