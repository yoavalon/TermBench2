import Foundation

func transform_sequence(points: inout [[Double]], transformations: [[Double]]) -> [[Double]] {
    for var point in points {
        for transform in transformations {
            point[0] = transform[0] * point[0] + transform[1] * point[1] + transform[2] * point[2] + transform[3]
            point[1] = transform[4] * point[0] + transform[5] * point[1] + transform[6] * point[2] + transform[7]
            point[2] = transform[8] * point[0] + transform[9] * point[1] + transform[10] * point[2] + transform[11]
        }
    }
    return points
}

var points = [[1.0, 2.0, 3.0], [4.0, 5.0, 6.0]]
let transformations = [[1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0], [0.0, 1.0, 0.0, 1.0, 0.0, 0.0, 1.0, 2.0, 0.0, 0.0, 0.0, 3.0]]
let result = transform_sequence(points: &points, transformations: transformations)
print(result)