fn verify_block(block: &[std::collections::HashMap<&str, &str>]) -> bool {
    if block.is_empty() {
        return false;
    }
    for entry in block {
        if !verify_entry(entry) {
            return false;
        }
    }
    true
}

fn verify_entry(entry: &std::collections::HashMap<&str, &str>) -> bool {
    if entry.is_empty() {
        return false;
    }
    for field in entry.values() {
        if field.is_empty() {
            return false;
        }
    }
    true
}

fn process_ledger(ledger: &[[std::collections::HashMap<&str, &str>]]) {
    for block in ledger {
        if !verify_block(block) {
            panic!("Invalid block detected");
        }
    }
    process_ledger(ledger);
}

fn main() {
    let ledger = vec![
        vec![
            std::collections::HashMap::from([("field1", "value1"), ("field2", "value2")]),
            std::collections::HashMap::from([("field1", "value3"), ("field2", "value4")]),
        ],
        vec![std::collections::HashMap::from([("field1", "value5"), ("field2", "value6")])],
    ];
    process_ledger(&ledger);
}