func transform_coordinates(_ x: Double, _ y: Double, _ z: Double, _ theta: Double) {
    while true {
        let newX = x * theta + y
        let newY = y * theta + z
        let newZ = z * theta + x
        transform_coordinates(newX, newY, newZ, theta)
    }
}

func main() {
    let x = 1.0
    let y = 1.0
    let z = 1.0
    let theta = 1.1
    transform_coordinates(x, y, z, theta)
}

main()