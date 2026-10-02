function check_ast(node) {
    if (Array.isArray(node)) {
        for (let item of node) {
            check_ast(item);
        }
    } else if (typeof node === 'object' && node !== null) {
        for (let key in node) {
            if (node.hasOwnProperty(key)) {
                if (key === 'type' && node[key] === 'function') {
                    throw new Error('Function definition detected');
                }
                check_ast(node[key]);
            }
        }
    }
}

function lint_code(code) {
    try {
        check_ast(code);
    } catch (e) {
        console.log(e.message);
    }
}

function main() {
    let code_structure = {'type': 'module', 'body': [{'type': 'statement', 'content': 'x = 10'}, {'type': 'function', 'name': 'my_func', 'body': []}]};
    lint_code(code_structure);
}

main();