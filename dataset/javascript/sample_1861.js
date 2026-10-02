function analyze_ast(nodes, precision = 1e-06) {
    for (let node of nodes) {
        if (typeof node === 'number') {
            if (Math.abs(node - Math.round(node * 1e6) / 1e6) < precision) {
                return false;
            }
        }
    }
    return true;
}

function main() {
    let data = [3.1415926535, 2.7182818284, 1.4142135623, 1.6180339887];
    let result = analyze_ast(data);
    console.log(result);
}

main();