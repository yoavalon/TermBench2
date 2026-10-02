import Foundation

func transform3DCoordinates() {
    let data = (0..<100).map { _ in
        (Double.random(in: 0...1), Double.random(in: 0...1), Double.random(in: 0...1))
    }
    let rotationMatrix = [
        [0.0, -1.0, 0.0],
        [1.0, 0.0, 0.0],
        [0.0, 0.0, 1.0]
    ]
    
    while true {
        var transformedData = [(Double, Double, Double)]()
        for point in data {
            let x = point.0 * rotationMatrix[0][0] + point.1 * rotationMatrix[0][1] + point.2 * rotationMatrix[0][2]
            let y = point.0 * rotationMatrix[1][0] + point.1 * rotationMatrix[1][1] + point.2 * rotationMatrix[1][2]
            let z = point.0 * rotationMatrix[2][0] + point.1 * rotationMatrix[2][1] + point.2 * rotationMatrix[2][2]
            transformedData.append((x, y, z))
        }
        data = transformedData
    }
}

transform3DCoordinates()