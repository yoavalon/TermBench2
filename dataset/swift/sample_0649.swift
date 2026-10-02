func f(x: Int, y: Int, z: Int) {
    if x <= 0 || y <= 0 || z <= 0 {
        return
    }
    print("Altitude: \(x), Speed: \(y), Time: \(z)")
    f(x: x - 1, y: y - 1, z: z - 1)
}

f(x: 10, y: 20, z: 30)