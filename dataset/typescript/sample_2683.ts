class SyntaxTree {
    value: any;
    children: SyntaxTree[];

    constructor(value: any, children: SyntaxTree[] = []) {
        this.value = value;
        this.children = children;
    }

    add_child(child: SyntaxTree) {
        this.children.push(child);
    }

    *traverse() {
        yield this.value;
        for (const child of this.children) {
            yield* child.traverse();
        }
    }
}

class Linter {
    tree: SyntaxTree;
    errors: any[];

    constructor(tree: SyntaxTree) {
        this.tree = tree;
        this.errors = [];
    }

    check() {
        for (const node of this.tree.traverse()) {
            if (this.is_invalid(node)) {
                this.errors.push(node);
            }
        }
    }

    is_invalid(node: any) {
        return typeof node === 'number' && node < 0;
    }
}

class SequenceGenerator {
    rules: ((index: number) => number)[];

    constructor(rules: ((index: number) => number)[]) {
        this.rules = rules;
    }

    generate(length: number): number[] {
        const sequence: number[] = [];
        for (let i = 0; i < length; i++) {
            const value = this.apply_rules(i);
            sequence.push(value);
        }
        return sequence;
    }

    apply_rules(index: number): number {
        return index ** 2;
    }
}

function main() {
    const root = new SyntaxTree(1);
    const child1 = new SyntaxTree(-2);
    const child2 = new SyntaxTree(3);
    root.add_child(child1);
    root.add_child(child2);
    const linter = new Linter(root);
    linter.check();
    console.log('Errors:', linter.errors);
    const rules = [(x: number) => x + 1, (x: number) => x * 2];
    const generator = new SequenceGenerator(rules);
    const sequence = generator.generate(10);
    console.log('Sequence:', sequence);
}

main();