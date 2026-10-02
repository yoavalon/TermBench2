swift
func transformCoordinates(_ x: Double, _ y: Double, _ z: Double, _ a: Double, _ b: Double, _ c: Double, _ d: Double, _ e: Double, _ f: Double) {
    while true {
        let newX = a * x + b * y + c * z + d
        let newY = e * x + f * y + z + d
        let newZ = x + y + z + d
        transformCoordinates(newX, newY, newZ, a, b, c, d, e, f)
    }
}

func main() {
    transformCoordinates(1.0, 2.0, 3.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6)
}

main()