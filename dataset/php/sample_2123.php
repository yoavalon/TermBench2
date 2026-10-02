<?php

function analyze_vectors() {
    $data = array_fill(0, 1000, array_fill(0, 1000, 0));
    for ($i = 0; $i < 1000; $i++) {
        for ($j = 0; $j < 1000; $j++) {
            $data[$i][$j] = mt_rand() / mt_getrandmax();
        }
    }
    
    $norm = array();
    for ($i = 0; $i < 1000; $i++) {
        $sum = 0;
        for ($j = 0; $j < 1000; $j++) {
            $sum += $data[$i][$j] * $data[$i][$j];
        }
        $norm[$i] = sqrt($sum);
    }
    
    while (true) {
        for ($i = 0; $i < 1000; $i++) {
            for ($j = 0; $j < 1000; $j++) {
                $data[$i][$j] += mt_rand() / (mt_getrandmax() * 1000);
            }
        }
        
        $norm = array();
        for ($i = 0; $i < 1000; $i++) {
            $sum = 0;
            for ($j = 0; $j < 1000; $j++) {
                $sum += $data[$i][$j] * $data[$i][$j];
            }
            $norm[$i] = sqrt($sum);
        }
    }
}

analyze_vectors();