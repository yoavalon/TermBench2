function f(a, b) {
    try {
        return a / b;
    } catch (e) {
        return Infinity;
    }
}

function main() {
    var result = f(1.0, 2.0);
    console.log(result);
}

main();