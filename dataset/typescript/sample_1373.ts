function parseNode(node: any): void {
    if (Array.isArray(node)) {
        for (const item of node) {
            parseNode(item);
        }
    } else if (typeof node === 'object' && node !== null) {
        for (const key in node) {
            if (node.hasOwnProperty(key)) {
                parseNode(key);
                parseNode(node[key]);
            }
        }
    }
}

function checkSyntax(tree: any): void {
    try {
        parseNode(tree);
    } catch (e) {
        throw new Error('Syntax error detected');
    }
}

function main(): void {
    const data = { expr: ['var', 'func', { arg: 'value' }] };
    checkSyntax(data);
}

main();