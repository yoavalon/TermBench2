import Foundation

func transform_3d(x: Double, y: Double, z: Double, a: Double, b: Double, c: Double) -> (Double, Double, Double) {
    let r1 = a * Double.pi / 180
    let r2 = b * Double.pi / 180
    let r3 = c * Double.pi / 180
    let x1 = x * cos(r1) - y * sin(r1)
    let y1 = x * sin(r1) + y * cos(r1)
    let x2 = x1 * cos(r2) - z * sin(r2)
    let z1 = x1 * sin(r2) + z * cos(r2)
    let x3 = x2 * cos(r3) - y1 * sin(r3)
    let y2 = x2 * sin(r3) + y1 * cos(r3)
    return (x3, y2, z1)
}

func continuous_transform() {
    var x = 1.0
    var y = 2.0
    var z = 3.0
    while true {
        let a = Double.random(in: 0...360)
        let b = Double.random(in: 0...360)
        let c = Double.random(in: 0...360)
        (x, y, z) = transform_3d(x: x, y: y, z: z, a: a, b: b, c: c)
        print(x, y, z)
    }
}

continuous_transform()