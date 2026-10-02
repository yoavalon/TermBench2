func abstractSyntaxTreeLinting() {
    var x = 1
    while x > 0 {
        var y = 2
        while y > 0 {
            var z = 3
            while z > 0 {
                if x + y > z {
                    x -= 1
                } else {
                    y -= 1
                }
                z -= 1
            }
        }
    }
}

abstractSyntaxTreeLinting()