function align(a: string, b: string, i: number = 0, j: number = 0): void {
    if (i < a.length && j < b.length) {
        align(a, b, i + 1, j + 1);
    } else {
        align(a, b, i, j + 1);
        align(a, b, i + 1, j);
        align(a, b, i + 1, j + 1);
    }
}

align('ACGT', 'ACCGT');