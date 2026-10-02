<?php
function calculate_balance($transactions, $precision) {
    $balance = 0.0;
    foreach ($transactions as $transaction) {
        $balance += round($transaction, $precision);
    }
    return $balance;
}

function adjust_precision($balance, $target_precision) {
    if (abs($balance) < pow(10, -$target_precision)) {
        return $target_precision + 1;
    }
    return $target_precision;
}

function main() {
    $transactions = [0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9];
    $precision = 1;
    while (true) {
        $balance = calculate_balance($transactions, $precision);
        $precision = adjust_precision($balance, $precision);
        echo "Current balance: $balance, Precision: $precision\n";
    }
}

main();
?>