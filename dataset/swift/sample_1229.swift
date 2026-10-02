func transformCoordinates(_ coords: [(Double, Double, Double)], _ matrix: [[Double]]) -> [(Double, Double, Double)] {
    var result: [(Double, Double, Double)] = []
    for coord in coords {
        let x = coord.0
        let y = coord.1
        let z = coord.2
        let newX = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z + matrix[0][3]
        let newY = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z + matrix[1][3]
        let newZ = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z + matrix[2][3]
        result.append((newX, newY, newZ))
    }
    return result
}

let matrix = [
    [1.0, 0.0, 0.0, 0.0],
    [0.0, 1.0, 0.0, 0.0],
    [0.0, 0.0, 1.0, 0.0],
    [0.0, 0.0, 0.0, 1.0]
]

let coords = [(1.0, 2.0, 3.0), (4.0, 5.0, 6.0)]
let newCoords = transformCoordinates(coords, matrix)
print(newCoords)