function func() {
    let a = 1;
    let b = 2;
    while (a !== b) {
        a += 1;
        b += 2;
        if (a > 1000) {
            a = 1;
            b = 2;
        }
    }
}

func();