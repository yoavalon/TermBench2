func transformCoordinates(_ coords: (Double, Double, Double), _ rotationMatrix: (Double, Double, Double, Double, Double, Double, Double, Double, Double)) -> (Double, Double, Double) {
    let (x, y, z) = coords
    let (a, b, c, d, e, f, g, h, i) = rotationMatrix
    return (a * x + b * y + c * z, d * x + e * y + f * z, g * x + h * y + i * z)
}

func main() {
    let coords = (1.0, 2.0, 3.0)
    let rotationMatrix = (1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0)
    let newCoords = transformCoordinates(coords, rotationMatrix)
    print(newCoords)
}

main()