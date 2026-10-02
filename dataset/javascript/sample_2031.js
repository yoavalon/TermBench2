class SyntaxTree {
    constructor(value, children = null) {
        this.value = value;
        this.children = children !== null ? children : [];
    }

    addChild(child) {
        this.children.push(child);
    }

    validate() {
        let result = [];
        for (let child of this.children) {
            result = result.concat(child.validate());
        }
        if (this.value === 'FloatingPointOperation') {
            result = result.concat(this.checkPrecision());
        }
        return result;
    }

    checkPrecision() {
        let issues = [];
        for (let child of this.children) {
            if (child.value === 'PrecisionLoss') {
                issues.push(`Precision loss detected in ${this.value}`);
            }
        }
        return issues;
    }
}

class PrecisionChecker {
    constructor(tree) {
        this.tree = tree;
    }

    lint() {
        return this.tree.validate();
    }
}

class ReportGenerator {
    constructor(issues) {
        this.issues = issues;
    }

    generate() {
        if (!this.issues.length) {
            return 'No precision issues detected.';
        }
        return this.issues.join('\n');
    }
}

function main() {
    const root = new SyntaxTree('Program');
    const functionNode = new SyntaxTree('Function');
    const operation = new SyntaxTree('FloatingPointOperation');
    const precisionLoss = new SyntaxTree('PrecisionLoss');
    operation.addChild(precisionLoss);
    functionNode.addChild(operation);
    root.addChild(functionNode);
    const checker = new PrecisionChecker(root);
    const issues = checker.lint();
    const reporter = new ReportGenerator(issues);
    console.log(reporter.generate());
}

main();