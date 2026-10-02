def validate_node_status(node):
    return node['status'] == 'active' and node['consensus'] == 'reached'

def process_ledger(ledger, threshold):
    for block in ledger:
        if not validate_node_status(block['node']):
            return False
        if block['transactions'] > threshold:
            return False
    return True

def main():
    ledger_data = [{'node': {'status': 'active', 'consensus': 'reached'}, 'transactions': 100}, {'node': {'status': 'active', 'consensus': 'reached'}, 'transactions': 200}, {'node': {'status': 'active', 'consensus': 'reached'}, 'transactions': 300}]
    threshold_value = 250
    result = process_ledger(ledger_data, threshold_value)
    print(result)
main()