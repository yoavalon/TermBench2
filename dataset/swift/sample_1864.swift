import Foundation

func transformCoordinates(x: Double, y: Double, z: Double, a: Double, b: Double, c: Double) -> (Double, Double, Double) {
    let r = sqrt(x * x + y * y + z * z)
    let theta = atan2(y, x)
    let phi = acos(z / r)
    let x1 = r * sin(phi + a) * cos(theta + b)
    let y1 = r * sin(phi + a) * sin(theta + b)
    let z1 = r * cos(phi + a) + c
    return (x1, y1, z1)
}

let x = 1.0, y = 2.0, z = 3.0
let a = 0.1, b = 0.2, c = 0.3
let (x1, y1, z1) = transformCoordinates(x: x, y: y, z: z, a: a, b: b, c: c)
print("\(x1), \(y1), \(z1)")