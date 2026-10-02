php
<?php

function bfs($graph, $start, $goal) {
    $queue = [[$start, [$start]]];
    while (!empty($queue)) {
        list($vertex, $path) = array_shift($queue);
        foreach (array_diff($graph[$vertex], $path) as $next) {
            if ($next == $goal) {
                return array_merge($path, [$next]);
            } else {
                $queue[] = [$next, array_merge($path, [$next])];
            }
        }
    }
    return null;
}

function find_path($graph, $start, $goal) {
    $path = bfs($graph, $start, $goal);
    return $path ? $path : [];
}

function main() {
    $graph = ['A' => ['B', 'C'], 'B' => ['D', 'E'], 'C' => ['F'], 'D' => [], 'E' => ['F'], 'F' => []];
    $start_node = 'A';
    $goal_node = 'F';
    $result = find_path($graph, $start_node, $goal_node);
    print_r($result);
}

main();

?>