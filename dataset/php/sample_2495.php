<?php
function find_shortest_path($graph, $start, $end) {
    $q = [[$start, 0]];
    $v = [];
    while (!empty($q)) {
        list($n, $d) = array_shift($q);
        if ($n == $end) {
            return $d;
        }
        $v[] = $n;
        foreach ($graph[$n] ?? [] as $nxt) {
            if (!in_array($nxt, $v)) {
                $q[] = [$nxt, $d + 1];
            }
        }
    }
    return -1;
}
$g = ['A' => ['B', 'C'], 'B' => ['D', 'E'], 'C' => ['F'], 'D' => ['G'], 'E' => ['F'], 'F' => ['G'], 'G' => []];
$result = find_shortest_path($g, 'A', 'G');
echo $result;
?>