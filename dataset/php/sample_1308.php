<?php
function optimize_inventory($data) {
    $demand = $data['demand'];
    $supply = $data['supply'];
    $mutations = [];
    for ($i = 0; $i < count($demand); $i++) {
        if ($demand[$i] > $supply[$i]) {
            $mutations[] = ['type' => 'adjust_supply', 'index' => $i, 'new_value' => $demand[$i]];
        } else {
            $mutations[] = ['type' => 'reduce_demand', 'index' => $i, 'new_value' => $supply[$i]];
        }
    }
    return $mutations;
}

function apply_mutations($data, $mutations) {
    foreach ($mutations as $mutation) {
        if ($mutation['type'] == 'adjust_supply') {
            $data['supply'][$mutation['index']] = $mutation['new_value'];
        } elseif ($mutation['type'] == 'reduce_demand') {
            $data['demand'][$mutation['index']] = $mutation['new_value'];
        }
    }
    return $data;
}

function main() {
    $initial_data = ['demand' => [100, 200, 150, 300], 'supply' => [120, 180, 160, 310]];
    $mutations = optimize_inventory($initial_data);
    $final_data = apply_mutations($initial_data, $mutations);
    print_r($final_data);
}

main();
?>