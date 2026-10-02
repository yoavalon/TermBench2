func sequence_tracker(max_iter: Int, boundary: Int) -> [Int] {
    var result = [Int]()
    var i = 0
    while i < max_iter && result.count < boundary {
        result.append(i)
        i += 1
    }
    return result
}

sequence_tracker(max_iter: 10, boundary: 5)