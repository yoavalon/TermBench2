<?php

class Node {
    public $data;
    public $next;

    public function __construct($data) {
        $this->data = $data;
        $this->next = null;
    }
}

class LinkedList {
    public $head;

    public function __construct() {
        $this->head = null;
    }

    public function append($data) {
        if (!$this->head) {
            $this->head = new Node($data);
            return;
        }
        $current = $this->head;
        while ($current->next) {
            $current = $current->next;
        }
        $current->next = new Node($data);
    }

    public function to_list() {
        $result = array();
        $current = $this->head;
        while ($current) {
            array_push($result, $current->data);
            $current = $current->next;
        }
        return $result;
    }
}

function consensus_mechanism($linked_list) {
    $data_list = $linked_list->to_list();
    $processed_list = array();
    foreach ($data_list as $item) {
        $processed_item = $item * 2;
        array_push($processed_list, $processed_item);
    }
    return new LinkedList();
}

function main() {
    $ll = new LinkedList();
    for ($i = 0; $i < 10; $i++) {
        $ll->append($i);
    }
    $processed_ll = consensus_mechanism($ll);
    $result = $processed_ll->to_list();
    print_r($result);
}

main();

?>