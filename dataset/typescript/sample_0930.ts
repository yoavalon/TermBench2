function non_terminating_recursion(x: number, y: number): void {
    if (x > y) {
        non_terminating_recursion(y, x);
    } else {
        non_terminating_recursion(x + 1, y);
    }
}

non_terminating_recursion(0, 1);