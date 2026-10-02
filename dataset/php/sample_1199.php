<?php

class Node {
    public $value;
    public $children;

    function __construct($value) {
        $this->value = $value;
        $this->children = array();
    }

    function add_child($child_node) {
        array_push($this->children, $child_node);
    }
}

class Network {
    public $root;

    function __construct() {
        $this->root = null;
    }

    function build($depth, $current_depth=0, $parent=null) {
        if ($current_depth < $depth) {
            $new_node = new Node($current_depth);
            if ($parent) {
                $parent->add_child($new_node);
            } else {
                $this->root = $new_node;
            }
            for ($i = 0; $i < 2; $i++) {
                $this->build($depth, $current_depth + 1, $new_node);
            }
        }
    }

    function traverse($node) {
        if ($node) {
            yield $node->value;
            foreach ($node->children as $child) {
                yield from $this->traverse($child);
            }
        }
    }
}

class Optimizer {
    public $network;

    function __construct($network) {
        $this->network = $network;
    }

    function optimize() {
        foreach ($this->network->traverse($this->network->root) as $value) {
            print($value . "\n");
        }
        $this->optimize();
    }
}

function main() {
    $network = new Network();
    $network->build(5);
    $optimizer = new Optimizer($network);
    $optimizer->optimize();
}

main();
?>