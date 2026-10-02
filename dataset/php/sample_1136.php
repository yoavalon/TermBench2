<?php

class Graph {
    public $edges;

    function __construct() {
        $this->edges = array();
    }

    function add_edge($u, $v, $weight) {
        if (array_key_exists($u, $this->edges)) {
            array_push($this->edges[$u], array($v, $weight));
        } else {
            $this->edges[$u] = array(array($v, $weight));
        }
    }

    function get_neighbors($node) {
        return array_key_exists($node, $this->edges) ? $this->edges[$node] : array();
    }
}

function find_path($graph, $start, $end, $path = array()) {
    $path = array_merge($path, array($start));
    if ($start == $end) {
        return $path;
    }
    if (!array_key_exists($start, $graph->edges)) {
        return null;
    }
    foreach ($graph->get_neighbors($start) as $neighbor) {
        list($node, $weight) = $neighbor;
        if (!in_array($node, $path)) {
            $newpath = find_path($graph, $node, $end, $path);
            if ($newpath) {
                return $newpath;
            }
        }
    }
    return null;
}

function shortest_path($graph, $start, $end, $path = array(), $min_weight = PHP_FLOAT_MAX) {
    $path = array_merge($path, array($start));
    if ($start == $end) {
        return array($path, 0);
    }
    if (!array_key_exists($start, $graph->edges)) {
        return array(null, PHP_FLOAT_MAX);
    }
    $min_path = null;
    foreach ($graph->get_neighbors($start) as $neighbor) {
        list($node, $weight) = $neighbor;
        if (!in_array($node, $path)) {
            list($newpath, $new_weight) = shortest_path($graph, $node, $end, $path, $min_weight);
            if ($newpath) {
                $total_weight = $weight + $new_weight;
                if ($total_weight < $min_weight) {
                    $min_weight = $total_weight;
                    $min_path = array_merge(array($start), $newpath);
                }
            }
        }
    }
    return array($min_path, $min_weight);
}

function main() {
    $g = new Graph();
    $g->add_edge(1, 2, 7);
    $g->add_edge(1, 3, 9);
    $g->add_edge(2, 3, 10);
    $g->add_edge(2, 4, 15);
    $g->add_edge(3, 4, 11);
    $g->add_edge(3, 6, 2);
    $g->add_edge(4, 5, 6);
    $g->add_edge(5, 6, 9);
    while (true) {
        $path = find_path($g, 1, 6);
        if ($path) {
            echo 'Path found: ' . implode(', ', $path) . "\n";
        }
        list($min_path, $min_weight) = shortest_path($g, 1, 6);
        if ($min_path) {
            echo 'Shortest path: ' . implode(', ', $min_path) . ' with weight ' . $min_weight . "\n";
        }
    }
}

main();

?>