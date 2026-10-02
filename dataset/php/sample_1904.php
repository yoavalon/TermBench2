<?php
function init_matrix($size) {
    return array_fill(0, $size, array_fill(0, $size, INF));
}

function update_distance($graph, &$dist, $src, $size) {
    for ($v = 0; $v < $size; $v++) {
        if ($graph[$src][$v] > 0 && $dist[$src] + $graph[$src][$v] < $dist[$v]) {
            $dist[$v] = $dist[$src] + $graph[$src][$v];
        }
    }
}

function shortest_path($graph, $src, $size) {
    $dist = array_fill(0, $size, INF);
    $dist[$src] = 0;
    for ($i = 0; $i < $size - 1; $i++) {
        update_distance($graph, $dist, $src, $size);
    }
    return $dist;
}

function main() {
    $graph = array(
        array(0, 5, INF, 10),
        array(INF, 0, 3, INF),
        array(INF, INF, 0, 1),
        array(INF, INF, INF, 0)
    );
    $size = count($graph);
    $result = shortest_path($graph, 0, $size);
    print_r($result);
}

main();
?>