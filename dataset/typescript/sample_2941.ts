class Node {
    value: any;
    left: Node | null;
    right: Node | null;

    constructor(value: any, left: Node | null = null, right: Node | null = null) {
        this.value = value;
        this.left = left;
        this.right = right;
    }
}

function generate_sequence(root: Node | null): any[] {
    let sequence: any[] = [];
    if (root) {
        sequence.push(root.value);
        sequence = sequence.concat(generate_sequence(root.left));
        sequence = sequence.concat(generate_sequence(root.right));
    }
    return sequence;
}

function validate_sequence(seq: any[]): string[] {
    let errors: string[] = [];
    if (!seq) {
        errors.push('Empty sequence detected.');
    }
    if (new Set(seq).size !== seq.length) {
        errors.push('Duplicate values found in sequence.');
    }
    if (seq.some(x => [Array, Object, Set].some(t => x instanceof t))) {
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