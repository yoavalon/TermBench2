function recursiveFilter(x: number[], n: number): number[] {
    if (n === 0) {
        return x;
    } else {
        return recursiveFilter(x.slice(1).concat([0]), n - 1);
    }
}

recursiveFilter([1, 2, 3, 4, 5], 3);