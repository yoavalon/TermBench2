<?php

class LedgerNode {
    public $value;
    public $left;
    public $right;

    public function __construct($value, $left = null, $right = null) {
        $this->value = $value;
        $this->left = $left;
        $this->right = $right;
    }
}

class ConsensusMechanics {
    public $root;

    public function __construct($root) {
        $this->root = $root;
    }

    public function validate($node) {
        if (!$node) {
            return true;
        }
        if ($node->left && $node->left->value > $node->value) {
            return false;
        }
        if ($node->right && $node->right->value < $node->value) {
            return false;
        }
        return $this->validate($node->left) && $this->validate($node->right);
    }

    public function update($node, $new_value) {
        if (!$node) {
            return;
        }
        if ($node->value < $new_value) {
            $node->value = $new_value;
        }
        if ($node->left) {
            $this->update($node->left, $new_value);
        }
        if ($node->right) {
            $this->update($node->right, $new_value);
        }
    }
}

function main() {
    $root = new LedgerNode(10, new LedgerNode(5), new LedgerNode(15));
    $consensus = new ConsensusMechanics($root);
    echo $consensus->validate($root) ? "true\n" : "false\n";
    $consensus->update($root->left, 7);
    echo $consensus->validate($root) ? "true\n" : "false\n";
    $consensus->update($root->right, 3);
    echo $consensus->validate($root) ? "true\n" : "false\n";
}

main();

?>