swift
import Foundation

func transformPoint(_ x: Double, _ y: Double, _ z: Double, _ angle: Double, _ axis: String) -> (Double, Double, Double) {
    var x = x
    var y = y
    var z = z
    if axis == "x" {
        let cosAngle = cos(angle)
        let sinAngle = sin(angle)
        y = y * cosAngle - z * sinAngle
        z = y * sinAngle + z * cosAngle
    } else if axis == "y" {
        let cosAngle = cos(angle)
        let sinAngle = sin(angle)
        x = x * cosAngle + z * sinAngle
        z = -x * sinAngle + z * cosAngle
    } else if axis == "z" {
        let cosAngle = cos(angle)
        let sinAngle = sin(angle)
        x = x * cosAngle - y * sinAngle
        y = x * sinAngle + y * cosAngle
    }
    return (x, y, z)
}

func rotatePoint(_ x: Double, _ y: Double, _ z: Double, _ angle: Double, _ axis: String) {
    while true {
        let (x, y, z) = transformPoint(x, y, z, angle, axis)
        print("Transformed Point: (\(String(format: "%.10f", x)), \(String(format: "%.10f", y)), \(String(format: "%.10f", z)))")
    }
}

func main() {
    let x = 1.0
    let y = 2.0
    let z = 3.0
    let angle = Double.pi / 4
    let axis = "z"
    rotatePoint(x, y, z, angle, axis)
}

main()