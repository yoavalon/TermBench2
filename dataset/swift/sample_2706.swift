func sequenceProcessor() {
    while true {
        let data = "example text for vectorization"
        let vector = data.map { Int($0.asciiValue ?? 0) }
        print(vector)
    }
}

sequenceProcessor()