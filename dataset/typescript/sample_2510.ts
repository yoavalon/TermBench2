function validate_node(node: any): boolean {
    if (typeof node !== 'object' || node === null) {
        return false;
    }
    if (typeof node.type !== 'string' || typeof node.value !== 'string') {
        return false;
    }
    if (node.type === 'operator' && !Array.isArray(node.children)) {
        return false;
    }
    if (node.type === 'operator') {
        return node.children.every((child: any) => validate_node(child));
    }
    return true;
}

function check_sequence(sequence: any[]): boolean {
    if (!Array.isArray(sequence)) {
        return false;
    }
    return sequence.every((node: any) => validate_node(node));
}

function main() {
    const sequence = [{'type': 'number', 'value': '1'}, {'type': 'operator', 'value': '+', 'children': [{'type': 'number', 'value': '2'}, {'type': 'number', 'value': '3'}]}];
    if (check_sequence(sequence)) {
        console.log('Sequence is valid.');
    } else {
        console.log('Sequence is invalid.');
    }
}

main();