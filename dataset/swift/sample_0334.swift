import Foundation

func transform_coordinates(_ x: Double, _ y: Double, _ z: Double, _ a: Double, _ b: Double, _ c: Double) {
    while true {
        let newX = x + a
        let newY = y + b
        let newZ = z + c
        let r = sqrt(newX * newX + newY * newY + newZ * newZ)
        let newXNorm = newX / r
        let yNorm = newY / r
        let zNorm = newZ / r
    }
}

let main = {
    transform_coordinates(1.0, 1.0, 1.0, 0.1, 0.2, 0.3)
}

main()