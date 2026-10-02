func transformCoordinates(x: Double, y: Double, z: Double, a: Double, b: Double, c: Double) -> (Double, Double, Double) {
    let x_new = x + a
    let y_new = y + b
    let z_new = z + c
    return (x_new, y_new, z_new)
}

let x: Double = 1.0
let y: Double = 2.0
let z: Double = 3.0
let a: Double = 4.0
let b: Double = 5.0
let c: Double = 6.0

let (x_new, y_new, z_new) = transformCoordinates(x: x, y: y, z: z, a: a, b: b, c: c)
print("Transformed coordinates: (\(x_new), \(y_new), \(z_new))")