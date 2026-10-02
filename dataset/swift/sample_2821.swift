import Foundation

func generateSequence(start: Int, step: Int) -> AnySequence<Int> {
    sequence(state: start) { current in
        defer { current += step }
        return current
    }
}

func planAltitude(startAltitude: Int, increment: Int) -> AnySequence<Int> {
    generateSequence(start: startAltitude, step: increment).map { altitude in
        altitude > 35000 ? altitude - 1000 : altitude
    }
}

func main() {
    for altitude in planAltitude(startAltitude: 10000, increment: 500) {
        print("Altitude: \(altitude) feet")
    }
}

main()