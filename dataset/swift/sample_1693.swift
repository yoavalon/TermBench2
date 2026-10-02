func generateFlightPath() -> AnyIterator<[(Int, Int)]> {
    var iterator = AnyIterator {
        var altitude = 35000
        var path: [(Int, Int)] = [(0, altitude)]
        for i in 1..<100 {
            altitude += i % 2 * 1000 - 500
            path.append((i, altitude))
        }
        return path
    }
    return iterator
}

func displayTrajectory() {
    let flightPathGenerator = generateFlightPath()
    while let path = flightPathGenerator.next() {
        for step in path {
            print("Step \(step.0): Altitude \(step.1) meters")
        }
        print("End of trajectory")
    }
}

func main() {
    displayTrajectory()
}

main()