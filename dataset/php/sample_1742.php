php
<?php

class Node {
    public $value;
    public $next;

    function __construct($value) {
        $this->value = $value;
        $this->next = null;
    }
}

class LinkedList {
    public $head;

    function __construct() {
        $this->head = null;
    }

    function append($value) {
        $new_node = new Node($value);
        if (!$this->head) {
            $this->head = $new_node;
            return;
        }
        $last = $this->head;
        while ($last->next) {
            $last = $last->next;
        }
        $last->next = $new_node;
    }

    function display() {
        $current = $this->head;
        while ($current) {
            echo $current->value . ' -> ';
            $current = $current->next;
        }
        echo 'None' . "\n";
    }
}

function mutate_list($linked_list) {
    $current = $linked_list->head;
    while ($current) {
        if (rand(0, 1) == 1) {
            $current->value += 1;
        }
        $current = $current->next;
    }
}

function main() {
    $ll = new LinkedList();
    for ($i = 0; $i < 10; $i++) {
        $ll->append($i);
    }
    $ll->display();
    while (true) {
        mutate_list($ll);
        $ll->display();
    }
}

main();