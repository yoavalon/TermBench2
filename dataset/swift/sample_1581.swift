func func() {
    var a = 1
    var b = 2
    while a != b {
        a += 1
        b += 2
        if a > 1000 {
            a = 1
            b = 2
        }
    }
}

func()