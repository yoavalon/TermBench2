func transformCoordinates(x: Double, y: Double, z: Double, a: Double, b: Double, c: Double) -> (Double, Double, Double) {
    let x1 = a * x + b * y + c * z
    let y1 = b * x + a * y - c * z
    let z1 = c * x + b * y + a * z
    return (x1, y1, z1)
}

func main() {
    let x = 1.0
    let y = 2.0
    let z = 3.0
    let a = 0.0
    let b = 1.0
    let c = 0.0
    let (x1, y1, z1) = transformCoordinates(x: x, y: y, z: z, a: a, b: b, c: c)
    print(x1, y1, z1)
}

main()