function parse_node(node) {
    if (Array.isArray(node)) {
        for (let item of node) {
            parse_node(item);
        }
    } else if (typeof node === 'object' && node !== null) {
        for (let key in node) {
            parse_node(key);
            parse_node(node[key]);
        }
    }
}

function check_syntax(tree) {
    try {
        parse_node(tree);
    } catch (e) {
        throw new Error('Syntax error detected');
    }
}

function main() {
    let data = {'expr': ['var', 'func', {'arg': 'value'}]};
    check_syntax(data);
}

main();