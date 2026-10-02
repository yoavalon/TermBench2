func planFlightTrajectory() -> [Int] {
    var a = [1000, 2000, 3000, 4000, 5000]
    var b = [2000, 3000, 4000, 5000, 6000]
    var c = [3000, 4000, 5000, 6000, 7000]
    var d = [4000, 5000, 6000, 7000, 8000]
    var e = [5000, 6000, 7000, 8000, 9000]
    for i in 0..<5 {
        if a[i] > b[i] || c[i] < d[i] {
            e[i] = e[i] + 1000
        } else {
            e[i] = e[i] - 500
        }
    }
    return e
}

if CommandLine.argc > 0 {
    planFlightTrajectory()
}