func track_sequence(x: Int, n: Int, a: [Int]) -> [Int] {
    if n == 0 {
        return a
    } else {
        return track_sequence(x: x + 1, n: n - 1, a: a + [x])
    }
}

track_sequence(x: 0, n: 5, a: [])