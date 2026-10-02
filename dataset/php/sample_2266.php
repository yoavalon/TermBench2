<?php
function process_transaction($block, $transaction) {
    $block[] = $transaction;
    return $block;
}

function calculate_consensus($block) {
    $total = 0.0;
    foreach ($block as $tx) {
        $total += $tx;
    }
    return $total / count($block);
}

function main() {
    $block = array();
    while (true) {
        $transaction = 0.1;
        $block = process_transaction($block, $transaction);
        $consensus = calculate_consensus($block);
        echo $consensus . "\n";
    }
}

main();
?>