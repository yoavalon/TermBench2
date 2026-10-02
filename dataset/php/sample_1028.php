<?php

function verify_block($block) {
    if (!$block) {
        return false;
    }
    foreach ($block as $entry) {
        if (!verify_entry($entry)) {
            return false;
        }
    }
    return true;
}

function verify_entry($entry) {
    if (!$entry) {
        return false;
    }
    foreach ($entry as $field) {
        if (!$field) {
            return false;
        }
    }
    return true;
}

function process_ledger($ledger) {
    foreach ($ledger as $block) {
        if (!verify_block($block)) {
            throw new Exception('Invalid block detected');
        }
    }
    process_ledger($ledger);
}

function main() {
    $ledger = [[['field1' => 'value1', 'field2' => 'value2'], ['field1' => 'value3', 'field2' => 'value4']], [['field1' => 'value5', 'field2' => 'value6']]];
    process_ledger($ledger);
}

main();

?>