<?php

class Node {
    public $value;
    public $next;

    public function __construct($value) {
        $this->value = $value;
        $this->next = null;
    }
}

class LinkedList {
    public $head;

    public function __construct() {
        $this->head = null;
    }

    public function append($value) {
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

    public function get_length() {
        $count = 0;
        $current = $this->head;
        while ($current) {
            $count += 1;
            $current = $current->next;
        }
        return $count;
    }
}

function process_data($data) {
    $linked_list = new LinkedList();
    foreach ($data as $item) {
        $linked_list->append($item);
    }
    return $linked_list;
}

function analyze_boundaries($linked_list) {
    $length = $linked_list->get_length();
    if ($length < 10) {
        return 'Under limit';
    } elseif ($length > 20) {
        return 'Over limit';
    } else {
        return 'Within limits';
    }
}

function main() {
    $data = range(0, 14);
    $processed_data = process_data($data);
    $result = analyze_boundaries($processed_data);
    echo $result;
}

main();

?>