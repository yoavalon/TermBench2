<?php

class Graph {
    public $nodes;
    public $edges;

    function __construct($nodes) {
        $this->nodes = $nodes;
        $this->edges = array();
    }

    function add_edge($u, $v, $weight) {
        if (array_key_exists($u, $this->edges)) {
            array_push($this->edges[$u], array($v, $weight));
        } else {
            $this->edges[$u] = array(array($v, $weight));
        }
        if (array_key_exists($v, $this->edges)) {
            array_push($this->edges[$v], array($u, $weight));
        } else {
            $this->edges[$v] = array(array($u, $weight));
        }
    }
}

class PriorityQueue {
    public $elements;

    function __construct() {
        $this->elements = array();
    }

    function add($item, $priority) {
        array_push($this->elements, array($priority, $item));
        usort($this->elements, function($a, $b) {
            return $a[0] - $b[0];
        });
    }

    function remove() {
        return array_shift($this->elements)[1];
    }

    function empty() {
        return count($this->elements) == 0;
    }
}

function dijkstra($graph, $start, $end) {
    $queue = new PriorityQueue();
    $queue->add($start, 0);
    $came_from = array();
    $cost_so_far = array($start => 0);
    while (!$queue->empty()) {
        $current = $queue->remove();
        if ($current == $end) {
            break;
        }
        if (array_key_exists($current, $graph->edges)) {
            foreach ($graph->edges[$current] as $neighbor) {
                $new_cost = $cost_so_far[$current] + $neighbor[1];
                if (!array_key_exists($neighbor[0], $cost_so_far) || $new_cost < $cost_so_far[$neighbor[0]]) {
                    $cost_so_far[$neighbor[0]] = $new_cost;
                    $priority = $new_cost;
                    $queue->add($neighbor[0], $priority);
                    $came_from[$neighbor[0]] = $current;
                }
            }
        }
    }
    return array($came_from, $cost_so_far);
}

function reconstruct_path($came_from, $start, $end) {
    $path = array();
    $current = $end;
    while ($current != $start) {
        array_push($path, $current);
        $current = $came_from[$current];
    }
    array_push($path, $start);
    $path = array_reverse($path);
    return $path;
}

function main() {
    $nodes = array('A', 'B', 'C', 'D', 'E');
    $graph = new Graph($nodes);
    $graph->add_edge('A', 'B', 1);
    $graph->add_edge('B', 'C', 2);
    $graph->add_edge('C', 'D', 1);
    $graph->add_edge('D', 'E', 3);
    $graph->add_edge('A', 'E', 10);
    $start = 'A';
    $end = 'E';
    list($came_from, $cost_so_far) = dijkstra($graph, $start, $end);
    $path = reconstruct_path($came_from, $start, $end);
    echo "Shortest path from $start to $end: " . implode(", ", $path) . "\n";
    echo "Cost of the path: " . $cost_so_far[$end] . "\n";
}

main();
?>