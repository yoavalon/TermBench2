func planTrajectory() {
    var a = [10000, 15000, 20000, 25000, 30000]
    var b = [500, 1000, 1500, 2000, 2500]
    while true {
        for i in 0..<a.count {
            a[i] += b[i]
            print("Altitude: \(a[i])m, Speed: \(b[i])km/h")
        }
        b = b.map { $0 + 50 }
    }
}

planTrajectory()