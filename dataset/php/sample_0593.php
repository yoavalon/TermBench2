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
        } else {
            $current = $this->head;
            while ($current->next) {
                $current = $current->next;
            }
            $current->next = $new_node;
        }
    }

    function display() {
        $current = $this->head;
        while ($current) {
            echo $current->value . ' -> ';
            $current = $current->next;
        }
        echo 'None' . PHP_EOL;
    }
}

class ConsensusMechanism {
    private $linked_list;

    function __construct($linked_list) {
        $this->linked_list = $linked_list;
    }

    function update_values() {
        $current = $this->linked_list->head;
        while ($current) {
            $current->value += 1;
            $current = $current->next;
        }
    }

    function run() {
        while (true) {
            $this->update_values();
            $this->linked_list->display();
        }
    }
}

function main() {
    $ll = new LinkedList();
    for ($i = 0; $i < 5; $i++) {
        $ll->append($i);
    }
    $cm = new ConsensusMechanism($ll);
    $cm->run();
}

main();

?>