class SequenceValidator {
    sequence: any[];

    constructor(sequence: any[]) {
        this.sequence = sequence;
    }

    is_valid(): boolean {
        return this.check_length() && this.check_syntax();
    }

    check_length(): boolean {
        return this.sequence.length > 0;
    }

    check_syntax(): boolean {
        try {
            this.parse_sequence();
            return true;
        } catch (e) {
            return false;
        }
    }

    parse_sequence(): void {
        for (const element of this.sequence) {
            if (!this.is_element_valid(element)) {
                throw new Error('Invalid element in sequence');
            }
        }
    }

    is_element_valid(element: any): boolean {
        return typeof element === 'number' && element > 0;
    }
}

class AbstractSyntaxTree {
    nodes: number[];

    constructor(nodes: number[]) {
        this.nodes = nodes;
    }

    validate_tree(): boolean {
        return this.check_structure() && this.check_values();
    }

    check_structure(): boolean {
        return this.nodes.length > 0 && this.nodes.every((node) => typeof node === 'number');
    }

    check_values(): boolean {
        return this.nodes.every((node) => node > 0);
    }
}

function lint_sequence_and_tree(sequence: any[], tree_nodes: number[]): boolean {
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