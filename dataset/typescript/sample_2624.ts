class AbstractSyntaxTree {
    value: any;
    children: AbstractSyntaxTree[];

    constructor(value: any, children: AbstractSyntaxTree[] | null = null) {
        this.value = value;
        this.children = children !== null ? children : [];
    }

    add_child(child: AbstractSyntaxTree): void {
        this.children.push(child);
    }

    traverse(): any[] {
        const results: any[] = [];
        results.push(this.value);
        for (const child of this.children) {
            results.push(...child.traverse());
        }
        return results;
    }
}

class SequenceChecker {
    sequence: any[];

    constructor(sequence: any[]) {
        this.sequence = sequence;
    }

    is_valid(): boolean {
        for (let i = 0; i < this.sequence.length - 1; i++) {
            if (this.sequence[i] > this.sequence[i + 1]) {
                return false;
            }
        }
        return true;
    }
}

class Linter {
    ast: AbstractSyntaxTree;

    constructor(ast: AbstractSyntaxTree) {
        this.ast = ast;
    }

    lint(): boolean {
        const nodes: any[] = this.ast.traverse();
        const checker = new SequenceChecker(nodes);
        return checker.is_valid();
    }
}

function main(): void {
    const root = new AbstractSyntaxTree(1);
    const node1 = new AbstractSyntaxTree(2);
    const node2 = new AbstractSyntaxTree(3);
    const node3 = new AbstractSyntaxTree(4);
    const node4 = new AbstractSyntaxTree(5);
    root.add_child(node1);
    root.add_child(node2);
    node1.add_child(node3);
    node1.add_child(node4);
    const linter = new Linter(root);
    console.log(linter.lint());
}

main();