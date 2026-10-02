function validate_node(node) {
    if (typeof node !== 'object' || node === null) {
        return false;
    }
    if (!('type' in node) || !('value' in node)) {
        return false;
    }
    if (node['type'] === 'operator' && !('children' in node)) {
        return false;
    }
    if (node['type'] === 'operator') {
        return node['children'].every(validate_node);
    }
    return true;
}

function check_sequence(sequence) {
    if (!Array.isArray(sequence)) {
        return false;
    }
    return sequence.every(validate_node);
}

function main() {
    const sequence = [{'type': 'number', 'value': 1}, {'type': 'operator', 'value': '+', 'children': [{'type': 'number', 'value': 2}, {'type': 'number', 'value': 3}]}];
    if (check_sequence(sequence)) {
        console.log('Sequence is valid.');
    } else {
        console.log('Sequence is invalid.');
    }
}

main();