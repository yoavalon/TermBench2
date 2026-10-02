func transformCoordinates(x: Double, y: Double, z: Double, a: Double, b: Double, c: Double) -> (Double, Double, Double) {
    let x1 = x * a + y * b + z * c
    let y1 = x * b - y * a + z * c
    let z1 = x * c + y * c - z * a
    return (x1, y1, z1)
}

func main() {
    _ = transformCoordinates(x: 1.0, y: 2.0, z: 3.0, a: 0.5, b: 0.5, c: 0.5)
}

main()