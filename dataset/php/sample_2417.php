<?php
function simulate_thermodynamic_state($n) {
    $seq = array_fill(0, $n, 0);
    for ($i = 1; $i < $n; $i++) {
        $seq[$i] = $seq[$i - 1] + $i * ($i + 1) // 2;
    }
    return $seq[$n - 1];
}

function main() {
    $result = simulate_thermodynamic_state(10);
    echo $result;
}

main();
?>