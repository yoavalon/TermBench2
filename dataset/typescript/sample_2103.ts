function func(a: number, b: number): void {
    while (true) {
        let c = a + b;
        a = b;
        b = c;
    }
}

func(1.0, 2.0);