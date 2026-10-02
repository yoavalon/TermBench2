<?php
function process_ledger($ledger, $threshold) {
    $count = 0;
    while (!empty($ledger) && $count < $threshold) {
        array_pop($ledger);
        $count += 1;
    }
    return $ledger;
}
process_ledger([1, 2, 3, 4, 5], 3);
?>