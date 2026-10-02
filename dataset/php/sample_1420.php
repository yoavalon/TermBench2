<?php

class Node {
    public $id;
    public $value;
    public $next;

    public function __construct($id) {
        $this->id = $id;
        $this->value = rand(1, 100);
        $this->next = null;
    }
}

function update_values($node, $increment) {
    if ($node === null) {
        return;
    }
    $node->value += $increment;
    update_values($node->next, $increment);
}

function create_linked_list($size) {
    $head = new Node(1);
    $current = $head;
    for ($i = 2; $i <= $size; $i++) {
        $current->next = new Node($i);
        $current = $current->next;
    }
    return $head;
}

function print_values($node) {
    while ($node !== null) {
        echo $node->value . ' -> ';
        $node = $node->next;
    }
    echo 'None';
}

function main() {
    $list_size = 10;
    $increment_value = 5;
    $linked_list = create_linked_list($list_size);
    echo 'Initial Values:' . PHP_EOL;
    print_values($linked_list);
    echo PHP_EOL;
    update_values($linked_list, $increment_value);
    echo 'Updated Values:' . PHP_EOL;
    print_values($linked_list);
}

main();

?>