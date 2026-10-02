function optimize(): number {
    let x = 0, v = 0, p = 0, g = 0;
    for (let _ = 0; _ < 100; _++) {
        x = x + v;
        v = v + (p - x) + (g - x);
        if (x > 10) {
            break;
        }
    }
    return x;
}

optimize();