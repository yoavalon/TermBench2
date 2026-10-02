func transformCoordinates(_ x: Double, _ y: Double, _ z: Double, _ a: Double, _ b: Double, _ c: Double) {
    while true {
        let newX = a * x + b * y + c * z
        let newY = a * y + b * z + c * x
        let newZ = a * z + b * x + c * y
    }
}

func main() {
    transformCoordinates(1.0, 2.0, 3.0, 0.5, 0.5, 0.5)
}

main()