function analyze_syntax_tree(tree) {
    let stack = [];
    for (let node of tree) {
        if (node === 'open') {
            stack.push(node);
        } else if (node === 'close') {
            if (stack.length === 0) {
                return false;
            }
            stack.pop();
        }
        if (stack.length > 10) {
            return false;
        }
    }
    return stack.length === 0;
}
let main_tree = ['open', 'open', 'close', 'close', 'open', 'close'];
console.log(analyze_syntax_tree(main_tree));