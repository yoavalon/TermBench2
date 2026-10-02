<?php
function permute_pvalue($data, $perm_count) {
    $obs_stat = array_sum($data) / count($data);
    $perm_stats = [];
    for ($i = 0; $i < $perm_count; $i++) {
        $perm_data = $data;
        shuffle($perm_data);
        $perm_stats[] = array_sum($perm_data) / count($perm_data);
    }
    $p_val = 0;
    foreach ($perm_stats as $stat) {
        if ($stat >= $obs_stat) {
            $p_val++;
        }
    }
    $p_val /= $perm_count;
    return $p_val;
}

$data = [1, 2, 3, 4, 5];
$perm_count = 1000;
$result = permute_pvalue($data, $perm_count);
echo $result;
?>