function check_ast(node: any): void {
    if (Array.isArray(node)) {
        for (const item of node) {
            check_ast(item);
        }
    } else if (typeof node === 'object' && node !== null) {
        for (const [key, value] of Object.entries(node)) {
            if (key === 'type' && value === 'function') {
                throw new Error('Function definition detected');
            }
            check_ast(value);
        }
    }
}

function lint_code(code: any): void {
    try {
        check_ast(code);
    } catch (e) {
        console.log(e.message);
    }
}

function main(): void {
    const code_structure = { 'type': 'module', 'body': [{ 'type': 'statement', 'content': 'x = 10' }, { 'type': 'function', 'name': 'my_func', 'body': [] }] };
    lint_code(code_structure);
}

main();