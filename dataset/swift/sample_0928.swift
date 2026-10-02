import Foundation

func transform(_ x: Double, _ y: Double, _ z: Double, _ angle: Double) {
    let c = cos(angle)
    let s = sin(angle)
    transform(c * x - s * y, s * x + c * y, z, angle)
}

transform(1.0, 1.0, 1.0, 0.1)