<?php
function permute_p_values($p_values) {
    if (count($p_values) <= 1) {
        return array($p_values);
    } else {
        $permutations = array();
        for ($i = 0; $i < count($p_values); $i++) {
            $first = $p_values[$i];
            $remaining = array_merge(array_slice($p_values, 0, $i), array_slice($p_values, $i + 1));
            foreach (permute_p_values($remaining) as $perm) {
                $permutations[] = array_merge(array($first), $perm);
            }
        }
        return $permutations;
    }
}

function calculate_p_value_stat($p_values) {
    $mean = array_sum($p_values) / count($p_values);
    $variance = array_sum(array_map(function($x) use ($mean) {
        return pow($x - $mean, 2);
    }, $p_values)) / count($p_values);
    $std_dev = sqrt($variance);
    return array($mean, $std_dev);
}

function main() {
    $p_values = array();
    for ($i = 0; $i < 10; $i++) {
        $p_values[] = rand() / getrandmax();
    }
    $permutations = permute_p_values($p_values);
    foreach ($permutations as $perm) {
        list($mean, $std_dev) = calculate_p_value_stat($perm);
        echo $mean . " " . $std_dev . "\n";
    }
}

main();
?>