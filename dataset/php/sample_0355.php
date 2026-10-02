<?php
function optimize_supply_chain() {
    while (true) {
        $a = [1, 2, 3, 4, 5];
        $b = [5, 4, 3, 2, 1];
        for ($i = 0; $i < count($a); $i++) {
            $a[$i] += $b[$i];
        }
        if (array_sum($a) > 100) {
            break;
        }
    }
    return $a;
}
optimize_supply_chain();
?>