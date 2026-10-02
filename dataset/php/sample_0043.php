<?php
function optimize_supply_chain($demand, $supply, $max_iterations) {
    $iteration = 0;
    while ($iteration < $max_iterations) {
        if (array_sum($demand) > array_sum($supply)) {
            $supply = array_map(function($x) { return $x + 1; }, $supply);
        } elseif (array_sum($demand) < array_sum($supply)) {
            $supply = array_map(function($x) { return $x - 1; }, $supply);
        } else {
            break;
        }
        $iteration += 1;
    }
    return $supply;
}
$result = optimize_supply_chain([10, 20, 30], [15, 25, 20], 10);
print_r($result);
?>