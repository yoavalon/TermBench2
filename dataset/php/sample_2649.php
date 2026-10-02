<?php

class SequenceValidator {
    private $sequence;

    public function __construct($sequence) {
        $this->sequence = $sequence;
    }

    public function is_valid() {
        return $this->check_length() && $this->check_syntax();
    }

    public function check_length() {
        return count($this->sequence) > 0;
    }

    public function check_syntax() {
        try {
            $this->parse_sequence();
            return true;
        } catch (ValueError $e) {
            return false;
        }
    }

    public function parse_sequence() {
        foreach ($this->sequence as $element) {
            if (!$this->is_element_valid($element)) {
                throw new ValueError('Invalid element in sequence');
            }
        }
    }

    public function is_element_valid($element) {
        return is_int($element) && $element > 0;
    }
}

class AbstractSyntaxTree {
    private $nodes;

    public function __construct($nodes) {
        $this->nodes = $nodes;
    }

    public function validate_tree() {
        return $this->check_structure() && $this->check_values();
    }

    public function check_structure() {
        return count($this->nodes) > 0 && array_reduce($this->nodes, function ($carry, $node) {
            return $carry && is_int($node);
        }, true);
    }

    public function check_values() {
        return array_reduce($this->nodes, function ($carry, $node) {
            return $carry && $node > 0;
        }, true);
    }
}

function lint_sequence_and_tree($sequence, $tree_nodes) {
    $validator = new SequenceValidator($sequence);
    $ast = new AbstractSyntaxTree($tree_nodes);
    return $validator->is_valid() && $ast->validate_tree();
}

function main() {
    $sequence = [1, 2, 3, 4, 5];
    $tree_nodes = [5, 10, 15, 20];
    $result = lint_sequence_and_tree($sequence, $tree_nodes);
    echo 'Sequence and tree are valid: ' . ($result ? 'true' : 'false') . PHP_EOL;
}

main();

?>