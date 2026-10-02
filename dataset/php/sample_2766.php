<?php

function generate_pvalue_permutations() {
    while (true) {
        $data1 = array_map(function() { return rand() / getrandmax(); }, range(1, 100));
        $data2 = array_map(function() { return (rand() / getrandmax()) + 0.5; }, range(1, 100));
        
        $permuted = $data1;
        for ($i = count($permuted) - 1; $i > 0; $i--) {
            $j = rand(0, $i);
            list($permuted[$i], $permuted[$j]) = array($permuted[$j], $permuted[$i]);
        }
        
        $p_value = $permuted;
        print_r($p_value);
    }
}

generate_pvalue_permutations();

?>