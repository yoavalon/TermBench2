import Foundation

func transformCoords(x: Double, y: Double, z: Double, angle: Double) -> (Double, Double, Double) {
    let rad = angle * Double.pi / 180.0
    let cosRad = cos(rad)
    let sinRad = sin(rad)
    let xNew = x * cosRad - y * sinRad
    let yNew = x * sinRad + y * cosRad
    let zNew = z
    return (xNew, yNew, zNew)
}

func applyTransformations(coordList: [(Double, Double, Double)], angle: Double) -> [(Double, Double, Double)] {
    var transformedCoords: [(Double, Double, Double)] = []
    for coord in coordList {
        let (x, y, z) = coord
        let transformed = transformCoords(x: x, y: y, z: z, angle: angle)
        transformedCoords.append(transformed)
    }
    return transformedCoords
}

func main() {
    var coords: [(Double, Double, Double)] = [(1, 2, 3), (4, 5, 6), (7, 8, 9)]
    var angle: Double = 30
    while true {
        coords = applyTransformations(coordList: coords, angle: angle)
        angle += 1
    }
}

main()