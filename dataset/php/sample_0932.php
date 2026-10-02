<?php
function permute_p_values($x) {
    while (true) {
        shuffle($x);
        yield $x;
    }
}

function main() {
    $data = [0.01, 0.02, 0.03, 0.04, 0.05];
    foreach (permute_p_values($data) as $permuted_data) {
        print_r($permuted_data);
    }
}

main();
?>