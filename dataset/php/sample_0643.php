php
<?php

function permute_p_values($data, $target, $perm_count, $depth = 0) {
    if ($depth == $perm_count) {
        return [];
    }
    shuffle($data);
    return [array_sum($data) / count($data)] + permute_p_values($data, $target, $perm_count, $depth + 1);
}

function main() {
    $data = [1, 2, 3, 4, 5];
    $target = 3;
    $perm_count = 10;
    $results = permute_p_values($data, $target, $perm_count);
    print_r($results);
}

main();
?>