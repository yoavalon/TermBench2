<?php
function validate_ledger($data, $index = 0) {
    if ($index >= count($data) - 1) {
        return true;
    }
    if ($data[$index] != $data[$index + 1]) {
        return false;
    }
    return validate_ledger($data, $index + 1);
}

function main() {
    $ledger_data = [1, 1, 1, 1, 1];
    echo validate_ledger($ledger_data);
}

main();
?>