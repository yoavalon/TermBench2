<?php

class SupplyChainOptimizer {

    public function __construct($nodes, $edges, $capacity) {
        $this->nodes = $nodes;
        $this->edges = $edges;
        $this->capacity = $capacity;
        $this->flow = array_fill(0, $nodes, array_fill(0, $nodes, 0));
    }

    public function find_path($source, $sink, &$parent) {
        $visited = array_fill(0, $this->nodes, false);
        $queue = array($source);
        $visited[$source] = true;
        while (!empty($queue)) {
            $u = array_shift($queue);
            for ($ind = 0; $ind < $this->nodes; $ind++) {
                if (!$visited[$ind] && $this->capacity[$u][$ind] - $this->flow[$u][$ind] > 0) {
                    array_push($queue, $ind);
                    $visited[$ind] = true;
                    $parent[$ind] = $u;
                    if ($ind == $sink) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    public function optimize_flow($source, $sink) {
        $parent = array_fill(0, $this->nodes, -1);
        $max_flow = 0;
        while ($this->find_path($source, $sink, $parent)) {
            $path_flow = PHP_INT_MAX;
            $s = $sink;
            while ($s != $source) {
                $path_flow = min($path_flow, $this->capacity[$parent[$s]][$s] - $this->flow[$parent[$s]][$s]);
                $s = $parent[$s];
            }
            $v = $sink;
            while ($v != $source) {
                $u = $parent[$v];
                $this->flow[$u][$v] += $path_flow;
                $this->flow[$v][$u] -= $path_flow;
                $v = $parent[$v];
            }
            $max_flow += $path_flow;
        }
        return $max_flow;
    }
}

function main() {
    $nodes = 6;
    $edges = 7;
    $capacity = array(
        array(0, 16, 13, 0, 0, 0),
        array(0, 0, 10, 12, 0, 0),
        array(0, 4, 0, 0, 14, 0),
        array(0, 0, 9, 0, 0, 20),
        array(0, 0, 0, 7, 0, 4),
        array(0, 0, 0, 0, 0, 0)
    );
    $source = 0;
    $sink = 5;
    $optimizer = new SupplyChainOptimizer($nodes, $edges, $capacity);
    $result = $optimizer->optimize_flow($source, $sink);
    echo 'The maximum possible flow is ' . $result . ' ';
}

main();