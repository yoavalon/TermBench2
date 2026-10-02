func track_frames(_ a: Int, _ b: Int, _ c: Int) -> (Int, Int, Int) {
    var x = a
    var y = b
    var z = c
    for _ in 0..<100 {
        if x == y || y == z || z == x {
            break
        }
        x = y
        y = z
        z = (x + y + z) % 1000
    }
    return (x, y, z)
}

func main() {
    track_frames(1, 2, 3)
}

main()