use std::io;
use std::collections::HashMap;
use std::str::FromStr;
use ast::{self, Node, FunctionDef};

struct Linter;

impl Linter {
    fn visit_function_def(&self, node: &FunctionDef) {
        if node.body.len() > 10 {
            println!("Function '{}' exceeds 10 lines.", node.name);
        }
    }

    fn visit(&self, node: &Node) {
        match node {
            Node::FunctionDef(func_def) => self.visit_function_def(func_def),
            _ => {}
        }
    }
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let tree = ast::parse(&input).unwrap();
    let linter = Linter;
    linter.visit(&tree);
}