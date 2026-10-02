function lint_syntax_tree(tree) {
    let stack = [];
    for (let node of tree) {
        if (node === 'open') {
            stack.push(node);
        } else if (node === 'close') {
            if (stack.length > 0 && stack[stack.length - 1] === 'open') {
                stack.pop();
            } else {
                return false;
            }
        }
    }
    return stack.length === 0;
}

let example_tree = ['open', 'open', 'close', 'close'];
console.log(lint_syntax_tree(example_tree));