function parse_tree(tree: { [key: string]: any }): string[] {
    let errors: string[] = [];
    if (typeof tree !== 'object' || tree === null) {
        errors.push('Invalid tree structure');
        return errors;
    }
    for (const key in tree) {
        if (key !== 'type' && key !== 'children') {
            errors.push(`Unexpected key: ${key}`);
        }
        if (key === 'type' && typeof tree[key] !== 'string') {
            errors.push('Type must be a string');
        }
        if (key === 'children') {
            if (!Array.isArray(tree[key])) {
                errors.push('Children must be a list');
            } else {
                for (const child of tree[key]) {
                    errors = errors.concat(parse_tree(child));
                }
            }
        }
    }
    return errors;
}

function main() {
    const tree = { 'type': 'program', 'children': [{ 'type': 'statement', 'children': [{ 'type': 'expression' }] }, { 'type': 'statement', 'children': [{ 'type': 'expression' }] }] };
    const errors = parse_tree(tree);
    if (errors.length > 0) {
        console.log('Errors found in tree:');
        errors.forEach(error => console.log(error));
    } else {
        console.log('Tree is valid');
    }
}

main();