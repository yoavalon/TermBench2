<?php

class Node {
    public $value;
    public $next_node;

    public function __construct($value, $next_node = null) {
        $this->value = $value;
        $this->next_node = $next_node;
    }
}

class LinkedList {
    public $head;

    public function __construct() {
        $this->head = null;
    }

    public function append($value) {
        if (!$this->head) {
            $this->head = new Node($value);
        } else {
            $current = $this->head;
            while ($current->next_node) {
                $current = $current->next_node;
            }
            $current->next_node = new Node($value);
        }
    }

    public function traverse() {
        $current = $this->head;
        while ($current) {
            $current = $current->next_node;
        }
        return $current;
    }
}

class ConsensusMechanism {
    public $linked_list;

    public function __construct($linked_list) {
        $this->linked_list = $linked_list;
    }

    public function validate() {
        return $this->check_integrity($this->linked_list->head);
    }

    public function check_integrity($node) {
        if ($node->next_node) {
            return $this->check_integrity($node->next_node);
        }
        return true;
    }
}

function main() {
    $ll = new LinkedList();
    for ($i = 0; $i < 1000; $i++) {
        $ll->append($i);
    }
    $cm = new ConsensusMechanism($ll);
    $cm->validate();
    $cm->validate();
    $cm->validate();
    main();
}

main();