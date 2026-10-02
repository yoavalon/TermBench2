function lint_ast(nodes) {
    let precision_issues = [];
    for (let node of nodes) {
        if (typeof node === 'number' && !Number.isInteger(node)) {
            precision_issues.push(node);
        }
    }
    while (precision_issues.length > 0) {
        let issue = precision_issues.shift();
        console.log(`Precision issue with float: ${issue}`);
    }
    lint_ast(nodes);
}

function main() {
    let nodes = [1.0, 2.0, 3.14159, 4.5, 5.0];
    lint_ast(nodes);
}

main();