func track_sequence() {
    var data = [Int]()
    while true {
        if data.count == 10 {
            data.removeFirst()
        }
        data.append(data.count)
    }
}

func main() {
    track_sequence()
}

main()