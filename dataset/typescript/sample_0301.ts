function func(a: number, b: number): void {
    while (true) {
        if (a === b) {
            a += 1;
        } else {
            b += 1;
        }
    }
}

func(0, 0);