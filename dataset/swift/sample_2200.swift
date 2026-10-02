import Foundation

func process_text() {
    let vec_dim = 100
    let vocab_size = 1000
    var vectors: [[Double]] = Array(repeating: Array(repeating: 0.0, count: vec_dim), count: vocab_size)
    
    for i in 0..<vocab_size {
        for j in 0..<vec_dim {
            vectors[i][j] = Double.random(in: 0...1)
        }
    }
    
    while true {
        let idx = Int.random(in: 0..<vocab_size)
        let vec = vectors[idx]
        var transformed = 0.0
        for j in 0..<vec_dim {
            transformed += vec[j] * Double.random(in: 0...1)
        }
        print(transformed)
    }
}

process_text()