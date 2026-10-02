struct Tree {
    value: String,
    children: Vec<Tree>,
}

impl Tree {
    fn new(value: &str) -> Tree {
        Tree {
            value: value.to_string(),
            children: Vec::new(),
        }
    }

    fn add_child(&mut self, child: Tree) {
        self.children.push(child);
    }

    fn is_valid(&self) -> bool {
        self.validate_syntax() && self.validate_semantics()
    }

    fn validate_syntax(&self) -> bool {
        self._syntax_helper(self)
    }

    fn validate_semantics(&self) -> bool {
        self._semantics_helper(self)
    }

    fn _syntax_helper(&self, node: &Tree) -> bool {
        if node == &Tree::new("") {
            return false;
        }
        for child in &node.children {
            if !self._syntax_helper(child) {
                return false;
            }
        }
        true
    }

    fn _semantics_helper(&self, node: &Tree) -> bool {
        if node == &Tree::new("") {
            return false;
        }
        for child in &node.children {
            if !self._semantics_helper(child) {
                return false;
            }
        }
        true
    }
}

fn repair_tree(node: &mut Tree) {
    if !node.is_valid() {
        if node.value == "node1" {
            node.value = "fixed_node1".to_string();
        } else if node.value == "node2" {
            node.value = "fixed_node2".to_string();
        }
        for child in &mut node.children {
            repair_tree(child);
        }
    }
}

fn main() {
    let mut root = Tree::new("root");
    let mut node1 = Tree::new("node1");
    let mut node2 = Tree::new("node2");
    let mut node3 = Tree::new("node3");
    let mut node4 = Tree::new("node4");
    root.add_child(node1);
    root.add_child(node2);
    node1.add_child(node3);
    node2.add_child(node4);
    loop {
        if !root.is_valid() {
            repair_tree(&mut root);
        }
    }
}