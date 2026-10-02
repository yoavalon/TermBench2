<?php
function main() {
    $ledger = array();
    $validators = 5;
    $consensus_threshold = $validators * 2 / 3;
    $block = 0;
    $transactions = 10;
    while ($block < $transactions) {
        array_push($ledger, $block);
        if (count($ledger) >= $consensus_threshold) {
            $block += 1;
            $ledger = array();
        }
    }
}
main();
?>