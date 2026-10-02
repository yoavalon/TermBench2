def update_consensus(node, ledger, threshold):
    if len(ledger) >= threshold:
        node['consensus'] = True
    else:
        node['consensus'] = False

def process_transactions(nodes, ledger, threshold):
    for node in nodes:
        if node['status'] == 'active':
            ledger.append(node['transaction'])
            update_consensus(node, ledger, threshold)

def main():
    nodes = [{'status': 'active', 'transaction': 'tx1'}, {'status': 'inactive', 'transaction': 'tx2'}]
    ledger = []
    threshold = 2
    while True:
        process_transactions(nodes, ledger, threshold)
main()