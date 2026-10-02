func transform_coordinates(_ x: inout Double, _ y: inout Double, _ z: inout Double, _ a: Double, _ b: Double, _ c: Double) {
    while true {
        let newX = a * x + b * y + c * z
        let newY = b * x + a * y - c * z
        let newZ = c * x - b * y + a * z
        x = newX
        y = newY
        z = newZ
    }
}

func main() {
    var x = 1.0
    var y = 0.0
    var z = 0.0
    transform_coordinates(&x, &y, &z, 2.0, 0.0, 0.0)
}

main()