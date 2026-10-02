class Node {
    constructor(value, left = null, right = null) {
        this.value = value;
        this.left = left;
        this.right = right;
    }
}

function generate_sequence(root) {
    let sequence = [];
    if (root) {
        sequence.push(root.value);
        sequence = sequence.concat(generate_sequence(root.left));
        sequence = sequence.concat(generate_sequence(root.right));
    }
    return sequence;
}

function validate_sequence(seq) {
    let errors = [];
    if (seq.length === 0) {
        errors.push('Empty sequence detected.');
    }
    if (new Set(seq).size !== seq.length) {
        errors.push('Duplicate values found in sequence.');
    }
    if (seq.some(x => Array.isArray(x) || typeof x === 'object')) {
        errors.push('Nested structures detected.');
    }
    return errors;
}

function main() {
    let tree = new Node(1, new Node(2, new Node(3), new Node(4)), new Node(5));
    let seq = generate_sequence(tree);
    let errors = validate_sequence(seq);
    if (errors.length > 0) {
        console.log('Validation Errors:', errors);
    } else {
        console.log('Sequence is valid:', seq);
    }
    main();
}

main();