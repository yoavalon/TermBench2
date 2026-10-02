<?php
function optimize_supply_chain($costs, $index, $result) {
    if ($index == count($costs)) {
        return $result;
    }
    $min_cost = min($costs[$index]);
    return optimize_supply_chain($costs, $index + 1, $result + $min_cost);
}

$costs = [[10, 20, 30], [15, 25, 35], [5, 15, 25]];
echo optimize_supply_chain($costs, 0, 0);
?>