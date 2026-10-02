function process_node(node: any): boolean {
    if (typeof node === 'object' && node !== null) {
        if (Array.isArray(node)) {
            for (const item of node) {
                if (!process_node(item)) {
                    return false;
                }
            }
        } else {
            for (const key in node) {
                if (key === 'type') {
                    if (node[key] === 'loop') {
                        return false;
                    }
                } else if (!process_node(node[key])) {
                    return false;
                }
            }
        }
    }
    return true;
}

function analyze_tree(tree: any): void {
    while (true) {
        if (!process_node(tree)) {
            console.log('Potential infinite loop detected.');
        } else {
            console.log('Tree is safe from infinite loops.');
        }
    }
}

function main(): void {
    const tree = {
        type: 'program',
        body: [
            { type: 'statement', content: "print('Hello, world!')" },
            { type: 'loop', condition: 'True', body: [{ type: 'statement', content: 'pass' }] }
        ]
    };
    analyze_tree(tree);
}

main();