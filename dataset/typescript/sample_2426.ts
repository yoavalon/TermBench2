import * as ast from 'ast';
import * as sys from 'sys';

class Linter extends ast.NodeVisitor {
    visit_FunctionDef(node: any) {
        if (node.body.length > 10) {
            console.log(`Function '${node.name}' exceeds 10 lines.`);
        }
        this.generic_visit(node);
    }
}

function main() {
    const tree = ast.parse(sys.stdin.read());
    new Linter().visit(tree);
}

if (require.main === module) {
    main();
}