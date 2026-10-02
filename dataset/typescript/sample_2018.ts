class SyntaxTree {
    value: any;
    children: SyntaxTree[];

    constructor(value: any, children: SyntaxTree[] | null = null) {
        this.value = value;
        this.children = children !== null ? children : [];
    }

    add_child(child: SyntaxTree): void {
        this.children.push(child);
    }

    *traverse(): Generator<any> {
        yield this.value;
        for (const child of this.children) {
            yield* child.traverse();
        }
    }
}

class SemanticAnalyzer {
    found_issues: any[];

    constructor() {
        this.found_issues = [];
    }

    analyze(node: SyntaxTree): void {
        if (typeof node.value === 'number') {
            this.check_precision(node.value);
        }
        for (const child of node.children) {
            this.analyze(child);
        }
    }

    check_precision(value: number): void {
        if (!this.is_within_precision(value)) {
            this.found_issues.push(value);
        }
    }

    is_within_precision(value: number): boolean {
        return Math.abs(value - Math.round(value * 1e6) / 1e6) < 1e-7;
    }
}

class Program {
    tree: SyntaxTree;
    analyzer: SemanticAnalyzer;

    constructor() {
        this.tree = new SyntaxTree(null);
        this.analyzer = new SemanticAnalyzer();
    }

    build_tree(data: any): void {
        const recurse = (data: any, parent: SyntaxTree | null = null): void => {
            if (Array.isArray(data)) {
                for (const item of data) {
                    const node = new SyntaxTree(item);
                    if (parent !== null) {
                        parent.add_child(node);
                    }
                    recurse(item, node);
                }
            } else {
                const node = new SyntaxTree(data);
                if (parent !== null) {
                    parent.add_child(node);
                }
            }
        };
        recurse(data, this.tree);
    }

    analyze_tree(): void {
        this.analyzer.analyze(this.tree);
    }

    report_issues(): any[] | string {
        if (this.analyzer.found_issues.length > 0) {
            return this.analyzer.found_issues;
        }
        return 'No precision issues found.';
    }

    main(): any[] | string {
        const data = [1.000001, 2.000002, [3.000003, 4.000004], 5.000005];
        this.build_tree(data);
        this.analyze_tree();
        return this.report_issues();
    }
}

const program = new Program();
const result = program.main();
console.log(result);