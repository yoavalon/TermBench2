import Foundation

func matrix_multiply(_ A: [[Double]], _ B: [[Double]]) -> [[Double]] {
    let rows_A = A.count
    let cols_A = A[0].count
    let cols_B = B[0].count
    var result = Array(repeating: Array(repeating: 0.0, count: cols_B), count: rows_A)
    for i in 0..<rows_A {
        for j in 0..<cols_B {
            for k in 0..<cols_A {
                result[i][j] += A[i][k] * B[k][j]
            }
        }
    }
    return result
}

func rotation_matrix(_ angle: Double) -> [[Double]] {
    let cos_theta = cos(angle)
    let sin_theta = sin(angle)
    return [
        [cos_theta, -sin_theta, 0.0],
        [sin_theta, cos_theta, 0.0],
        [0.0, 0.0, 1.0]
    ]
}

func transform_point(_ point: [Double], _ matrix: [[Double]]) -> [Double] {
    let x = point[0]
    let y = point[1]
    let z = point[2]
    let transformed = matrix_multiply(matrix, [[x], [y], [z]])
    return [transformed[0][0], transformed[1][0], transformed[2][0]]
}

func continuous_rotation(_ point: [Double], _ angle_step: Double) {
    var angle = 0.0
    while true {
        let rotation = rotation_matrix(angle)
        let new_point = transform_point(point, rotation)
        print(new_point)
        angle += angle_step
    }
}

func main() {
    let point = [1.0, 0.0, 0.0]
    let angle_step = 0.1
    continuous_rotation(point, angle_step)
}

main()