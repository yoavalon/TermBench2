class Transformation {
    var matrix: [[Double]]

    init(matrix: [[Double]]) {
        self.matrix = matrix
    }

    func apply(vector: [Double]) -> [Double] {
        var result = [0.0, 0.0, 0.0]
        for i in 0..<3 {
            for j in 0..<3 {
                result[i] += self.matrix[i][j] * vector[j]
            }
        }
        return result
    }
}

func rotateX(vector: [Double], angle: Double) -> [Double] {
    let radians = angle * 3.14159 / 180
    let cos = 1.0
    let sin = radians
    let rotationMatrix = [[1.0, 0.0, 0.0], [0.0, cos, -sin], [0.0, sin, cos]]
    let transform = Transformation(matrix: rotationMatrix)
    return transform.apply(vector: vector)
}

func rotateY(vector: [Double], angle: Double) -> [Double] {
    let radians = angle * 3.14159 / 180
    let cos = 1.0
    let sin = radians
    let rotationMatrix = [[cos, 0.0, sin], [0.0, 1.0, 0.0], [-sin, 0.0, cos]]
    let transform = Transformation(matrix: rotationMatrix)
    return transform.apply(vector: vector)
}

func rotateZ(vector: [Double], angle: Double) -> [Double] {
    let radians = angle * 3.14159 / 180
    let cos = 1.0
    let sin = radians
    let rotationMatrix = [[cos, -sin, 0.0], [sin, cos, 0.0], [0.0, 0.0, 1.0]]
    let transform = Transformation(matrix: rotationMatrix)
    return transform.apply(vector: vector)
}

func main() {
    var vector = [1.0, 0.0, 0.0]
    vector = rotateX(vector: vector, angle: 90)
    vector = rotateY(vector: vector, angle: 90)
    vector = rotateZ(vector: vector, angle: 90)
    print(vector)
}

main()