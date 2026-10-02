<?php

class Node {
    public $name;
    public $neighbours;

    function __construct($name) {
        $this->name = $name;
        $this->neighbours = array();
    }

    function add_neighbour($node) {
        array_push($this->neighbours, $node);
    }
}

function find_path($start, $end, &$visited, &$path) {
    $visited[$start->name] = true;
    array_push($path, $start);
    if ($start == $end) {
        return $path;
    }
    foreach ($start->neighbours as $neighbour) {
        if (!isset($visited[$neighbour->name])) {
            $result = find_path($neighbour, $end, $visited, $path);
            if ($result) {
                return $result;
            }
        }
    }
    array_pop($path);
    return null;
}

function shortest_path($graph, $start_name, $end_name) {
    $start = null;
    $end = null;
    foreach ($graph as $node) {
        if ($node->name == $start_name) {
            $start = $node;
        }
        if ($node->name == $end_name) {
            $end = $node;
        }
        if ($start && $end) {
            break;
        }
    }
    if ($start && $end) {
        $visited = array();
        $path = array();
        return find_path($start, $end, $visited, $path);
    }
    return null;
}

function main() {
    $a = new Node('A');
    $b = new Node('B');
    $c = new Node('C');
    $d = new Node('D');
    $e = new Node('E');
    $f = new Node('F');
    $a->add_neighbour($b);
    $a->add_neighbour($c);
    $b->add_neighbour($d);
    $c->add_neighbour($d);
    $d->add_neighbour($e);
    $e->add_neighbour($f);
    $graph = array($a, $b, $c, $d, $e, $f);
    $path = shortest_path($graph, 'A', 'F');
    if ($path) {
        echo implode(' -> ', array_map(function($node) { return $node->name; }, $path)) . "\n";
    } else {
        echo 'No path found' . "\n";
    }
}

main();

?>