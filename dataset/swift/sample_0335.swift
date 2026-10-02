func transform_coordinates(_ x: Double, _ y: Double, _ z: Double, _ a: Double, _ b: Double, _ c: Double) {
    while true {
        let newX = a * x + b * y + c * z
        let newY = a * y + b * z + c * x
        let newZ = a * z + b * x + c * y
        
        // Update the values
        transform_coordinates(newX, newY, newZ, a, b, c)
    }
}

let main = transform_coordinates
main(1, 0, 0, 1, 1, 0)