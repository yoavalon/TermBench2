function consensus(a, b) {
    if (a == b) {
        return a;
    }
    if (a > b) {
        return consensus(a - 1, b);
    }
    return consensus(a, b - 1);
}

function main() {
    var result = consensus(4, 5);
    console.log(result);
}

main();