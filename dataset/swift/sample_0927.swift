func transform(_ x: Double, _ y: Double, _ z: Double, _ a: Double, _ b: Double, _ c: Double) -> (Double, Double, Double) {
    let newX = a * x + b * y + c * z
    let newY = b * x + a * y
    let newZ = c * x + y
    return transform(newX, newY, newZ, a, b, c)
}

func main() {
    transform(1, 1, 1, 1.5, -0.5, 0)
}

main()