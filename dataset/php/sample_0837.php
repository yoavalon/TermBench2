php
<?php

class LogisticsOptimizer {
    public $data;

    function __construct($data) {
        $this->data = $data;
    }

    function find_optimal_route($current, $destination, $visited) {
        if ($current == $destination) {
            return array($destination);
        }
        $visited[] = $current;
        $neighbors = $this->data[$current] ?? array();
        foreach ($neighbors as $neighbor => $cost) {
            if (!in_array($neighbor, $visited)) {
                $path = $this->find_optimal_route($neighbor, $destination, $visited);
                if ($path) {
                    return array_merge(array($current), $path);
                }
            }
        }
        return null;
    }

    function calculate_cost($path) {
        $cost = 0;
        for ($i = 0; $i < count($path) - 1; $i++) {
            $cost += $this->data[$path[$i]][$path[$i + 1]] ?? INF;
        }
        return $cost;
    }

    function optimize($start, $end) {
        $path = $this->find_optimal_route($start, $end, array());
        if ($path) {
            return array($this->calculate_cost($path), $path);
        }
        return array(INF, array());
    }
}

function main() {
    $data = array('A' => array('B' => 10, 'C' => 15), 'B' => array('A' => 10, 'D' => 20), 'C' => array('A' => 15, 'D' => 30), 'D' => array('B' => 20, 'C' => 30));
    $optimizer = new LogisticsOptimizer($data);
    list($cost, $path) = $optimizer->optimize('A', 'D');
    echo 'Optimal Cost: ' . $cost . "\n";
    echo 'Optimal Path: ' . implode(', ', $path) . "\n";
}

main();