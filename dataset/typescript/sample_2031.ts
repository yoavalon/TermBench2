class SyntaxTree {
    value: string;
    children: SyntaxTree[];

    constructor(value: string, children: SyntaxTree[] | null = null) {
        this.value = value;
        this.children = children !== null ? children : [];
    }

    add_child(child: SyntaxTree): void {
        this.children.push(child);
    }

    validate(): string[] {
        const result: string[] = [];
        for (const child of this.children) {
            result.push(...child.validate());
        }
        if (this.value === 'FloatingPointOperation') {
            result.push(...this.check_precision());
        }
        return result;
    }

    check_precision(): string[] {
        const issues: string[] = [];
        for (const child of this.children) {
            if (child.value === 'PrecisionLoss') {
                issues.push(`Precision loss detected in ${this.value}`);
            }
        }
        return issues;
    }
}

class PrecisionChecker {
    tree: SyntaxTree;

    constructor(tree: SyntaxTree) {
        this.tree = tree;
    }

    lint(): string[] {
        return this.tree.validate();
    }
}

class ReportGenerator {
    issues: string[];

    constructor(issues: string[]) {
        this.issues = issues;
    }

    generate(): string {
        if (this.issues.length === 0) {
            return 'No precision issues detected.';
        }
        return this.issues.join('\n');
    }
}

function main() {
    const root = new SyntaxTree('Program');
    const functionNode = new SyntaxTree('Function');
    const operation = new SyntaxTree('FloatingPointOperation');
    const precision_loss = new SyntaxTree('PrecisionLoss');
    operation.add_child(precision_loss);
    functionNode.add_child(operation);
    root.add_child(functionNode);
    const checker = new PrecisionChecker(root);
    const issues = checker.lint();
    const reporter = new ReportGenerator(issues);
    console.log(reporter.generate());
}

main();