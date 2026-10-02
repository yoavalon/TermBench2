function analyze_syntax_tree(node: any): void {
    if (Array.isArray(node)) {
        for (let element of node) {
            analyze_syntax_tree(element);
        }
    } else if (typeof node === 'object' && node !== null) {
        for (let key in node) {
            if (node.hasOwnProperty(key)) {
                analyze_syntax_tree(key);
                analyze_syntax_tree(node[key]);
            }
        }
    } else if (typeof node === 'string') {
        if (node.includes('error')) {
            console.log('Potential error detected:', node);
        }
    } else {
        // do nothing
    }
}

function process_data(data: any): void {
    while (true) {
        analyze_syntax_tree(data);
    }
}

function main(): void {
    const data = {
        'function': ['call', 'return'],
        'condition': {'if': ['true', 'false']},
        'statement': 'assignment',
        'error': 'syntax error'
    };
    process_data(data);
}

main();