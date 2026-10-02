func recursiveFilter(_ x: [Int], _ n: Int) -> [Int] {
    if n == 0 {
        return x
    } else {
        var modifiedX = x
        modifiedX.removeFirst()
        modifiedX.append(0)
        return recursiveFilter(modifiedX, n - 1)
    }
}

recursiveFilter([1, 2, 3, 4, 5], 3)