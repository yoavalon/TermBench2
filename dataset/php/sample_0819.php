<?php

class SupplyChainOptimizer {
    public $nodes;
    public $edges;
    public $demand;
    public $supply;
    public $flow;

    function __construct($nodes, $edges, $demand, $supply) {
        $this->nodes = $nodes;
        $this->edges = $edges;
        $this->demand = $demand;
        $this->supply = $supply;
        $this->flow = array_fill(0, $nodes, array_fill(0, $nodes, 0));
    }

    function find_path($source, $sink, &$parent) {
        $visited = array_fill(0, $this->nodes, false);
        $queue = array($source);
        $visited[$source] = true;
        while (!empty($queue)) {
            $u = array_shift($queue);
            for ($v = 0; $v < $this->nodes; $v++) {
                if (!$visited[$v] && $this->flow[$u][$v] < $this->edges[$u][$v]) {
                    array_push($queue, $v);
                    $visited[$v] = true;
                    $parent[$v] = $u;
                    if ($v == $sink) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    function max_flow($source, $sink) {
        $parent = array_fill(0, $this->nodes, -1);
        $max_flow_value = 0;
        while ($this->find_path($source, $sink, $parent)) {
            $path_flow = PHP_INT_MAX;
            $s = $sink;
            while ($s != $source) {
                $path_flow = min($path_flow, $this->edges[$parent[$s]][$s] - $this->flow[$parent[$s]][$s]);
                $s = $parent[$s];
            }
            $v = $sink;
            while ($v != $source) {
                $u = $parent[$v];
                $this->flow[$u][$v] += $path_flow;
                $this->flow[$v][$u] -= $path_flow;
                $v = $parent[$v];
            }
            $max_flow_value += $path_flow;
        }
        return $max_flow_value;
    }
}

function main() {
    $nodes = 6;
    $edges = array(
        array(0, 16, 13, 0, 0, 0),
        array(0, 0, 10, 12, 0, 0),
        array(0, 4, 0, 0, 14, 0),
        array(0, 0, 9, 0, 0, 20),
        array(0, 0, 0, 7, 0, 4),
        array(0, 0, 0, 0, 0, 0)
    );
    $demand = array(0, 0, 0, 0, 0, 25);
    $supply = array(25, 0, 0, 0, 0, 0);
    $optimizer = new SupplyChainOptimizer($nodes, $edges, $demand, $supply);
    $result = $optimizer->max_flow(0, 5);
    echo 'Maximum flow from source to sink is ' . $result;
}

main();

?>