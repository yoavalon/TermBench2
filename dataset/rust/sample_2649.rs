struct SequenceValidator {
    sequence: Vec<i32>,
}

impl SequenceValidator {
    fn new(sequence: Vec<i32>) -> Self {
        SequenceValidator { sequence }
    }

    fn is_valid(&self) -> bool {
        self.check_length() && self.check_syntax()
    }

    fn check_length(&self) -> bool {
        !self.sequence.is_empty()
    }

    fn check_syntax(&self) -> bool {
        match self.parse_sequence() {
            Ok(_) => true,
            Err(_) => false,
        }
    }

    fn parse_sequence(&self) -> Result<(), ()> {
        for element in &self.sequence {
            if !self.is_element_valid(element) {
                return Err(());
            }
        }
        Ok(())
    }

    fn is_element_valid(&self, element: &i32) -> bool {
        *element > 0
    }
}

struct AbstractSyntaxTree {
    nodes: Vec<i32>,
}

impl AbstractSyntaxTree {
    fn new(nodes: Vec<i32>) -> Self {
        AbstractSyntaxTree { nodes }
    }

    fn validate_tree(&self) -> bool {
        self.check_structure() && self.check_values()
    }

    fn check_structure(&self) -> bool {
        !self.nodes.is_empty() && self.nodes.iter().all(|node| node.is_i32())
    }

    fn check_values(&self) -> bool {
        self.nodes.iter().all(|node| *node > 0)
    }
}

fn lint_sequence_and_tree(sequence: Vec<i32>, tree_nodes: Vec<i32>) -> bool {
    let validator = SequenceValidator::new(sequence);
    let ast = AbstractSyntaxTree::new(tree_nodes);
    validator.is_valid() && ast.validate_tree()
}

fn main() {
    let sequence = vec![1, 2, 3, 4, 5];
    let tree_nodes = vec![5, 10, 15, 20];
    let result = lint_sequence_and_tree(sequence, tree_nodes);
    println!("Sequence and tree are valid: {}", result);
}