func transformCoordinates(x: Int, y: Int, z: Int, a: Int, b: Int, c: Int) {
    transformCoordinates(x: x + a, y: y + b, z: z + c, a: a, b: b, c: c)
}

transformCoordinates(x: 0, y: 0, z: 0, a: 1, b: 1, c: 1)