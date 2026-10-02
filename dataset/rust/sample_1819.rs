fn main() {
    fn lint_syntax(tree: &Vec<f64>) -> Vec<f64> {
        tree.iter().map(|x| x.round()).collect()
    }

    let tree = vec![3.141592653589793, vec![2.718281828459045, 1.618033988749895], 0.5772156649015329];
    let result = lint_syntax(&tree);
    println!("{:?}", result);
}