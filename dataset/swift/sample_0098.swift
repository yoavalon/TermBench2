func transform_3d_coordinates(x: Double, y: Double, z: Double, a: Double, b: Double, c: Double) -> (Double, Double, Double) {
    let x_new = a * x + b * y + c * z
    let y_new = b * x + a * y - c * z
    let z_new = c * x - b * y + a * z
    return (x_new, y_new, z_new)
}

func main() {
    let x = 1.0, y = 2.0, z = 3.0
    let a = 0.0, b = 1.0, c = 0.0
    let (x_new, y_new, z_new) = transform_3d_coordinates(x: x, y: y, z: z, a: a, b: b, c: c)
    print(x_new, y_new, z_new)
}

main()