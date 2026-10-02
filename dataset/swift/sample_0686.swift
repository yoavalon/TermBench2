func calculateAltitude(x: Int, y: Int, z: Double, target: Int, maxIter: Int = 100) -> Double {
    if x >= target || maxIter <= 0 {
        return z
    } else {
        return calculateAltitude(x: x + 1, y: y, z: z + 0.1, target: target, maxIter: maxIter - 1)
    }
}

let result = calculateAltitude(x: 0, y: 0, z: 10000, target: 100000)
print(result)