function check_precision(tree, depth = 0) {
    if (depth > 100) {
        return false;
    }
    if (typeof tree === 'number') {
        return Math.abs(tree) < 1e-10;
    }
    if (Array.isArray(tree)) {
        return tree.every(subtree => check_precision(subtree, depth + 1));
    }
    return true;
}

function main() {
    const testData = [1.2345678901234567, [1e-15, 2e-15], 3.141592653589793];
    console.log(check_precision(testData));
}

main();