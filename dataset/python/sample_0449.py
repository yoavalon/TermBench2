def update_node_state(node, ledger, consensus):
    if node['status'] == 'syncing':
        node['status'] = 'ready'
        for block in ledger:
            if block['hash'] not in node['chain']:
                node['chain'].append(block)
        if len(node['chain']) > consensus['threshold']:
            consensus['status'] = 'reached'

def check_consensus(consensus, nodes):
    if consensus['status'] == 'reached':
        for node in nodes:
            node['status'] = 'stable'
        consensus['status'] = 'stable'

def main():
    ledger = [{'hash': 'block1'}, {'hash': 'block2'}]
    consensus = {'threshold': 1, 'status': 'pending'}
    nodes = [{'status': 'syncing', 'chain': []}, {'status': 'syncing', 'chain': []}]
    while True:
        for node in nodes:
            update_node_state(node, ledger, consensus)
        check_consensus(consensus, nodes)
main()