<?php
function generate_sequence($n) {
    $sequence = array_fill(0, $n, 0);
    $sequence[0] = 0;
    $sequence[1] = 1;
    for ($i = 2; $i < $n; $i++) {
        $sequence[$i] = $sequence[$i - 1] + $sequence[$i - 2];
    }
    return $sequence;
}

function main() {
    $data = generate_sequence(10);
    print_r($data);
}
main();
?>