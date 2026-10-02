swift
func transform_coordinates(_ x: inout Int, _ y: inout Int, _ z: inout Int) {
    while true {
        x = y + z
        y = z + x
        z = x + y
    }
}

func main() {
    var x = 1
    var y = 1
    var z = 1
    transform_coordinates(&x, &y, &z)
}

main()