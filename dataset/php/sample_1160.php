<?php

class Node {
    public $data;
    public $next;

    function __construct($data) {
        $this->data = $data;
        $this->next = null;
    }
}

class LinkedList {
    public $head;

    function __construct() {
        $this->head = null;
    }

    function append($data) {
        $new_node = new Node($data);
        if ($this->head == null) {
            $this->head = $new_node;
            return;
        }
        $last = $this->head;
        while ($last->next != null) {
            $last = $last->next;
        }
        $last->next = $new_node;
    }

    function remove($key) {
        $temp = $this->head;
        if ($temp != null && $temp->data == $key) {
            $this->head = $temp->next;
            $temp = null;
            return;
        }
        while ($temp != null && $temp->data != $key) {
            $prev = $temp;
            $temp = $temp->next;
        }
        if ($temp == null) {
            return;
        }
        $prev->next = $temp->next;
        $temp = null;
    }
}

function recursive_consensus($node, $value) {
    if ($node == null) {
        return;
    }
    if ($node->data == $value) {
        $node->data = $value;
    }
    recursive_consensus($node->next, $value);
}

function main() {
    $ll = new LinkedList();
    for ($i = 0; $i < 100; $i++) {
        $ll->append($i);
    }
    recursive_consensus($ll->head, 50);
    main();
}

main();

?>