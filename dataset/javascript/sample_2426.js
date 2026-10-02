function lintAst() {
    const { parse } = require('acorn');
    const fs = require('fs');
    const readline = require('readline');

    class Linter {
        visit(node) {
            if (node.type === 'FunctionDeclaration') {
                if (node.body.body.length > 10) {
                    console.log(`Function '${node.id.name}' exceeds 10 lines.`);
                }
            }
            node.body.forEach(child => this.visit(child));
        }
    }

    function main() {
        const rl = readline.createInterface({
            input: process.stdin,
            output: process.stdout
        });

        let code = '';
        rl.on('line', line => {
            code += line + '\n';
        });

        rl.on('close', () => {
            const tree = parse(code);
            new Linter().visit(tree);
        });
    }

    if (require.main === module) {
        main();
    }
}