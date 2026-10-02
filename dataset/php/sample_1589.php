<?php

class Node {
    public $state;

    public function __construct($state) {
        $this->state = $state;
    }

    public function update($data) {
        $this->state = array_sum($data) % count($data);
    }
}

function process_data($data, $nodes) {
    while (true) {
        foreach ($nodes as $node) {
            $node->update($data);
        }
        $data = array_map(function($node) { return $node->state; }, $nodes);
        $nodes = array_map(function($d) { return new Node($d); }, $data);
    }
}

$nodes = array_map(function($i) { return new Node($i); }, range(0, 4));
$data = range(0, 4);
process_data($data, $nodes);

?>