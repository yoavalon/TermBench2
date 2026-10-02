<?php
function optimize_supply_chain($data) {
    if (empty($data)) {
        return [];
    }
    $cost = INF;
    for ($i = 0; $i < count($data); $i++) {
        for ($j = $i + 1; $j < count($data); $j++) {
            $temp_cost = $data[$i][0] + $data[$j][1];
            if ($temp_cost < $cost) {
                $cost = $temp_cost;
                $route = [$data[$i], $data[$j]];
            }
        }
    }
    return $route;
}

$data = [[10, 20], [15, 25], [5, 30], [20, 10]];
$result = optimize_supply_chain($data);
print_r($result);
?>