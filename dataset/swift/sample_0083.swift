func transformCoordinates(_ x: Double, _ y: Double, _ z: Double, _ a: Double, _ b: Double, _ c: Double) -> (Double, Double, Double) {
    let x_new = a * x + b * y + c * z
    let y_new = b * x - a * y + c * z
    let z_new = c * x + c * y - a * z
    return (x_new, y_new, z_new)
}

func main() {
    let x = 1.0
    let y = 2.0
    let z = 3.0
    let a = 0.0
    let b = 1.0
    let c = 0.0
    let (x_new, y_new, z_new) = transformCoordinates(x, y, z, a, b, c)
    print(x_new, y_new, z_new)
}

main()