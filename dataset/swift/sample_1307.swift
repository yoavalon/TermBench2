import Foundation

func transformCoordinates(matrix: [[Double]], points: [Double]) -> [Double] {
    let result = matrix.enumerated().map { row in
        return row.element.enumerated().map { col in
            return col.element * points[col.offset]
        }.reduce(0, +)
    }
    return result
}

func rotate3D(x: Double, y: Double, z: Double, angle: Double) -> (Double, Double, Double) {
    let rad = angle * Double.pi / 180.0
    let c = cos(rad)
    let s = sin(rad)
    let rotMatrix = [
        [c, -s, 0],
        [s, c, 0],
        [0, 0, 1]
    ]
    let points = [x, y, z]
    let result = transformCoordinates(matrix: rotMatrix, points: points)
    return (result[0], result[1], result[2])
}

func main() {
    var x = 1.0, y = 2.0, z = 3.0
    let angle = 45.0
    (x, y, z) = rotate3D(x: x, y: y, z: z, angle: angle)
    print(x, y, z)
}

main()