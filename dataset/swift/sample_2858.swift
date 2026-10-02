func sequenceGenerator() -> AnyIterator<Int> {
    var x = 1
    return AnyIterator {
        defer { x += 1 }
        return x
    }
}

func flightPlanner(seqGen: AnyIterator<Int>) {
    for step in seqGen {
        if step % 50 == 0 {
            print("Cruise altitude adjusted at step \(step)")
        }
        if step % 100 == 0 {
            print("Trajectory correction initiated at step \(step)")
        }
    }
}

func main() {
    let gen = sequenceGenerator()
    flightPlanner(seqGen: gen)
}

main()