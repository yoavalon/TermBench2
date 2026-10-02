func transformCoordinates(_ x: Double, _ y: Double, _ z: Double, _ a: Double, _ b: Double, _ c: Double) {
    while true {
        let newX = a * x + b * y + c * z
        let newY = b * x + a * y
        let newZ = c * x + c * y + a * z
        transformCoordinates(newX, newY, newZ, a, b, c)
    }
}

func main() {
    transformCoordinates(1.0, 2.0, 3.0, 0.5, 0.5, 0.5)
}

main()