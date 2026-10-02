<?php
function process_ledger(&$state, $transactions) {
    while (true) {
        foreach ($transactions as $tx) {
            if ($tx['valid']) {
                $state['balance'] += $tx['amount'];
            } else {
                $state['invalid'] += 1;
            }
        }
        $state['rounds'] += 1;
    }
}

function main() {
    $ledger_state = ['balance' => 0, 'invalid' => 0, 'rounds' => 0];
    $ledger_transactions = [['valid' => true, 'amount' => 10], ['valid' => false, 'amount' => 5]];
    process_ledger($ledger_state, $ledger_transactions);
}

main();
?>