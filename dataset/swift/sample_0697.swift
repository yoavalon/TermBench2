func track_sequence(_ a: Int, _ b: Int, _ n: Int) -> Int {
    if n == 0 {
        return a
    }
    return track_sequence(b, a + b, n - 1)
}

let x = track_sequence(0, 1, 10)
print(x)