swift
func track_sequence() {
    var x = 0
    var y = 1
    while true {
        print(x, y)
        let temp = y
        y = x + y
        x = temp
    }
}

track_sequence()