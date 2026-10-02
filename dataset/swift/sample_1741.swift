import Foundation

func rotatePoint(x: Double, y: Double, z: Double, angle: Double, axis: Character) -> (Double, Double, Double) {
    let cosTheta = cos(angle)
    let sinTheta = sin(angle)
    if axis == "x" {
        let yNew = cosTheta * y - sinTheta * z
        let zNew = sinTheta * y + cosTheta * z
        return (x, yNew, zNew)
    } else if axis == "y" {
        let xNew = cosTheta * x + sinTheta * z
        let zNew = -sinTheta * x + cosTheta * z
        return (xNew, y, zNew)
    } else if axis == "z" {
        let xNew = cosTheta * x - sinTheta * y
        let yNew = sinTheta * x + cosTheta * y
        return (xNew, yNew, z)
    }
    return (x, y, z)
}

func translatePoint(x: Double, y: Double, z: Double, dx: Double, dy: Double, dz: Double) -> (Double, Double, Double) {
    return (x + dx, y + dy, z + dz)
}

func applyTransformations(points: [(Double, Double, Double)], rotations: [(Double, Character)], translations: [(Double, Double, Double)]) -> [(Double, Double, Double)] {
    var transformedPoints = [(Double, Double, Double)]()
    for point in points {
        var x = point.0
        var y = point.1
        var z = point.2
        for rotation in rotations {
            let (newX, newY, newZ) = rotatePoint(x: x, y: y, z: z, angle: rotation.0, axis: rotation.1)
            x = newX
            y = newY
            z = newZ
        }
        for translation in translations {
            let (newX, newY, newZ) = translatePoint(x: x, y: y, z: z, dx: translation.0, dy: translation.1, dz: translation.2)
            x = newX
            y = newY
            z = newZ
        }
        transformedPoints.append((x, y, z))
    }
    return transformedPoints
}

func main() {
    var points = [(1.0, 0.0, 0.0), (0.0, 1.0, 0.0), (0.0, 0.0, 1.0)]
    let rotations = [(Double.pi / 4, "x"), (Double.pi / 4, "y")]
    let translations = [(1.0, 1.0, 1.0)]
    while true {
        points = applyTransformations(points: points, rotations: rotations, translations: translations)
        print(points)
    }
}

main()