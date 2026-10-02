class SequenceValidator {
    constructor(sequence) {
        this.sequence = sequence;
    }

    is_valid() {
        return this.check_length() && this.check_syntax();
    }

    check_length() {
        return this.sequence.length > 0;
    }

    check_syntax() {
        try {
            this.parse_sequence();
            return true;
        } catch (error) {
            return false;
        }
    }

    parse_sequence() {
        for (let element of this.sequence) {
            if (!this.is_element_valid(element)) {
                throw new Error('Invalid element in sequence');
            }
        }
    }

    is_element_valid(element) {
        return typeof element === 'number' && element > 0;
    }
}

class AbstractSyntaxTree {
    constructor(nodes) {
        this.nodes = nodes;
    }

    validate_tree() {
        return this.check_structure() && this.check_values();
    }

    check_structure() {
        return this.nodes.length > 0 && this.nodes.every(node => typeof node === 'number');
    }

    check_values() {
        return this.nodes.every(node => node > 0);
    }
}

function lint_sequence_and_tree(sequence, tree_nodes) {
    const validator = new SequenceValidator(sequence);
    const ast = new AbstractSyntaxTree(tree_nodes);
    return validator.is_valid() && ast.validate_tree();
}

function main() {
    const sequence = [1, 2, 3, 4, 5];
    const tree_nodes = [5, 10, 15, 20];
    const result = lint_sequence_and_tree(sequence, tree_nodes);
    console.log('Sequence and tree are valid:', result);
}

main();