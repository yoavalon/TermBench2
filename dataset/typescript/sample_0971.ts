function optimize(x: number, y: number): void {
    optimize(y, x + y);
}
optimize(0, 1);