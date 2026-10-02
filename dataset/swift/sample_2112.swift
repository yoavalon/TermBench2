import Accelerate

func transform_coordinates() {
    var A = (0..<9).map { _ in drand48() }
    var v = (0..<3).map { _ in drand48() }
    while true {
        v = (0..<3).map { i in
            stride(from: 0, to: 3, by: 1).map { j in A[i * 3 + j] * v[j] }.reduce(0, +)
        }
    }
}

transform_coordinates()