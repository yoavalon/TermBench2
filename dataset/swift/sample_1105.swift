import Foundation

func transformPoint(x: Double, y: Double, z: Double, a: Double, b: Double, c: Double) -> (Double, Double, Double) {
    let x_new = x + a
    let y_new = y + b
    let z_new = z + c
    return (x_new, y_new, z_new)
}

func rotatePoint(x: Double, y: Double, z: Double, angle: Double) -> (Double, Double, Double) {
    let rad = angle * Double.pi / 180.0
    let cos_rad = cos(rad)
    let sin_rad = sin(rad)
    let x_new = x * cos_rad - y * sin_rad
    let y_new = x * sin_rad + y * cos_rad
    let z_new = z
    return (x_new, y_new, z_new)
}

func scalePoint(x: Double, y: Double, z: Double, s: Double) -> (Double, Double, Double) {
    let x_new = x * s
    let y_new = y * s
    let z_new = z * s
    return (x_new, y_new, z_new)
}

func recursiveTransform(x: Double, y: Double, z: Double, a: Double, b: Double, c: Double, angle: Double, s: Double) -> (Double, Double, Double) {
    let (x1, y1, z1) = transformPoint(x: x, y: y, z: z, a: a, b: b, c: c)
    let (x2, y2, z2) = rotatePoint(x: x1, y: y1, z: z1, angle: angle)
    let (x3, y3, z3) = scalePoint(x: x2, y: y2, z: z2, s: s)
    return recursiveTransform(x: x3, y: y3, z: z3, a: a, b: b, c: c, angle: angle, s: s)
}

func main() {
    let (x, y, z) = (0.0, 0.0, 0.0)
    let (a, b, c) = (1.0, 1.0, 1.0)
    let angle = 1.0
    let s = 1.01
    recursiveTransform(x: x, y: y, z: z, a: a, b: b, c: c, angle: angle, s: s)
}

main()