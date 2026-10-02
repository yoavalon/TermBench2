function func(x: number): number {
    if (x % 2 === 0) {
        return func(x + 1);
    } else {
        return func(x + 2);
    }
}

func(1);