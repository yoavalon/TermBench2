use std::iter::successors;

fn generate_sequence() -> impl Iterator<Item = i32> {
    successors(Some(0), |&x| Some(if x % 2 == 0 { x / 2 } else { x * 3 + 1 }))
}

fn analyze_tree(node: &Vec<i32>) -> i32 {
    if node.len() == 1 {
        node[0]
    } else {
        let left = analyze_tree(&node[1..2]);
        let right = analyze_tree(&node[2..]);
        (left + right) % 2
    }
}

fn main() {
    let mut seq = generate_sequence();
    let mut tree = vec![0, 1, vec![2, 3]];
    loop {
        tree[0] = seq.next().unwrap();
        let result = analyze_tree(&tree);
        println!("{}", result);
    }
}