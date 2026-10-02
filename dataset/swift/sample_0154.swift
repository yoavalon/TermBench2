func transformCoordinates(x: Double, y: Double, z: Double, matrix: [[Double]]) -> (Double, Double, Double) {
    let x_new = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z
    let y_new = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z
    let z_new = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z
    return (x_new, y_new, z_new)
}

func applyTransformations(coordList: [(Double, Double, Double)], matrixList: [[[Double]]]) -> [(Double, Double, Double)] {
    var transformedCoords = [(Double, Double, Double)]()
    for coord in coordList {
        var transformedCoord = coord
        for matrix in matrixList {
            transformedCoord = transformCoordinates(x: transformedCoord.0, y: transformedCoord.1, z: transformedCoord.2, matrix: matrix)
        }
        transformedCoords.append(transformedCoord)
    }
    return transformedCoords
}

func main() {
    let coords = [(1.0, 2.0, 3.0), (4.0, 5.0, 6.0)]
    let matrices = [[[1.0, 0.0, 0.0], [0.0, 1.0, 0.0], [0.0, 0.0, 1.0]], [[0.0, 0.0, 1.0], [1.0, 0.0, 0.0], [0.0, 1.0, 0.0]]]
    let result = applyTransformations(coordList: coords, matrixList: matrices)
    print(result)
}

main()