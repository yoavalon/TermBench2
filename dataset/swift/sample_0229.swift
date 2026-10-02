import Foundation

func matrix_multiply(_ A: [[Double]], _ B: [[Double]]) -> [[Double]] {
    let result = Array(repeating: Array(repeating: 0.0, count: B[0].count), count: A.count)
    for i in 0..<A.count {
        for j in 0..<B[0].count {
            for k in 0..<B.count {
                result[i][j] += A[i][k] * B[k][j]
            }
        }
    }
    return result
}

func translate_point(_ point: [Double], _ translation: [Double]) -> [Double] {
    let translation_matrix = [
        [1, 0, 0, translation[0]],
        [0, 1, 0, translation[1]],
        [0, 0, 1, translation[2]],
        [0, 0, 0, 1]
    ]
    let point_matrix = [
        [point[0]],
        [point[1]],
        [point[2]],
        [1]
    ]
    let transformed_point = matrix_multiply(translation_matrix, point_matrix)
    return [transformed_point[0][0], transformed_point[1][0], transformed_point[2][0]]
}

func rotate_point(_ point: [Double], _ angle: Double, _ axis: String) -> [Double] {
    let cosAngle = cos(angle)
    let sinAngle = sin(angle)
    var rotation_matrix: [[Double]] = []
    if axis == "x" {
        rotation_matrix = [
            [1, 0, 0, 0],
            [0, cosAngle, -sinAngle, 0],
            [0, sinAngle, cosAngle, 0],
            [0, 0, 0, 1]
        ]
    } else if axis == "y" {
        rotation_matrix = [
            [cosAngle, 0, sinAngle, 0],
            [0, 1, 0, 0],
            [-sinAngle, 0, cosAngle, 0],
            [0, 0, 0, 1]
        ]
    } else if axis == "z" {
        rotation_matrix = [
            [cosAngle, -sinAngle, 0, 0],
            [sinAngle, cosAngle, 0, 0],
            [0, 0, 1, 0],
            [0, 0, 0, 1]
        ]
    }
    let point_matrix = [
        [point[0]],
        [point[1]],
        [point[2]],
        [1]
    ]
    let transformed_point = matrix_multiply(rotation_matrix, point_matrix)
    return [transformed_point[0][0], transformed_point[1][0], transformed_point[2][0]]
}

func scale_point(_ point: [Double], _ scale: Double) -> [Double] {
    let scaling_matrix = [
        [scale, 0, 0, 0],
        [0, scale, 0, 0],
        [0, 0, scale, 0],
        [0, 0, 0, 1]
    ]
    let point_matrix = [
        [point[0]],
        [point[1]],
        [point[2]],
        [1]
    ]
    let transformed_point = matrix_multiply(scaling_matrix, point_matrix)
    return [transformed_point[0][0], transformed_point[1][0], transformed_point[2][0]]
}

func main() {
    var point = [1.0, 2.0, 3.0]
    let translation = [1.0, 1.0, 1.0]
    let angle = 30 * (Double.pi / 180)
    let scale_factor = 2.0
    point = translate_point(point, translation)
    point = rotate_point(point, angle, "z")
    point = scale_point(point, scale_factor)
    print(point)
}

main()