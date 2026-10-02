class SyntaxTree {
    constructor(value, children = []) {
        this.value = value;
        this.children = children;
    }

    addChild(child) {
        this.children.push(child);
    }

    *traverse() {
        yield this.value;
        for (let child of this.children) {
            yield* child.traverse();
        }
    }
}

class SemanticAnalyzer {
    constructor() {
        this.foundIssues = [];
    }

    analyze(node) {
        if (typeof node.value === 'number') {
            this.checkPrecision(node.value);
        }
        for (let child of node.children) {
            this.analyze(child);
        }
    }

    checkPrecision(value) {
        if (!this.isWithinPrecision(value)) {
            this.foundIssues.push(value);
        }
    }

    isWithinPrecision(value) {
        return Math.abs(value - Math.round(value * 1e5) / 1e5) < 1e-7;
    }
}

class Program {
    constructor() {
        this.tree = new SyntaxTree(null);
        this.analyzer = new SemanticAnalyzer();
    }

    buildTree(data) {
        const recurse = (data, parent = null) => {
            if (Array.isArray(data)) {
                for (let item of data) {
                    let node = new SyntaxTree(item);
                    if (parent !== null) {
                        parent.addChild(node);
                    }
                    recurse(item, node);
                }
            } else {
                let node = new SyntaxTree(data);
                if (parent !== null) {
                    parent.addChild(node);
                }
            }
        };
        recurse(data, this.tree);
    }

    analyzeTree() {
        this.analyzer.analyze(this.tree);
    }

    reportIssues() {
        if (this.analyzer.foundIssues.length > 0) {
            return this.analyzer.foundIssues;
        }
        return 'No precision issues found.';
    }

    main() {
        let data = [1.000001, 2.000002, [3.000003, 4.000004], 5.000005];
        this.buildTree(data);
        this.analyzeTree();
        return this.reportIssues();
    }
}

let program = new Program();
let result = program.main();
console.log(result);