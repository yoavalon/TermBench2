func transform_coordinates(x: Double, y: Double, z: Double, a: Double, b: Double, c: Double) -> (Double, Double, Double) {
    let x_prime = a * x + b * y + c * z
    let y_prime = b * x + a * y + c * z
    let z_prime = c * x + c * y + a * z
    return (x_prime, y_prime, z_prime)
}

func main() {
    let x = 1.0, y = 2.0, z = 3.0
    let a = 0.5, b = 0.5, c = 0.707
    let (x_prime, y_prime, z_prime) = transform_coordinates(x: x, y: y, z: z, a: a, b: b, c: c)
    print(x_prime, y_prime, z_prime)
}

main()