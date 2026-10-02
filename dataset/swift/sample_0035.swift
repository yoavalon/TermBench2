func transform_coordinates(x: Double, y: Double, z: Double, a: Double, b: Double, c: Double) -> (Double, Double, Double) {
    let x_new = a * x + b * y + c * z
    let y_new = b * x + a * y - c * z
    let z_new = c * x + b * y + a * z
    return (x_new, y_new, z_new)
}

if CommandLine.arguments.count > 0 {
    let result = transform_coordinates(x: 1.0, y: 2.0, z: 3.0, a: 0.0, b: 1.0, c: 0.0)
}