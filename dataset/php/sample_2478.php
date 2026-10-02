<?php
function calculate_consensus($a, $b, $n) {
    if ($n == 0) {
        return $a;
    } else {
        return calculate_consensus($b, ($a + $b) % 1000, $n - 1);
    }
}
$result = calculate_consensus(1, 1, 10);
echo $result;
?>