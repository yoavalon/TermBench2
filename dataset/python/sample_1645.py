def update_ledger(data, node):
    for key in data:
        data[key] += node[key]
    return data

def simulate_consensus(nodes):
    ledger = {k: 0 for k in nodes[0]}
    for node in nodes:
        ledger = update_ledger(ledger, node)
    return ledger

def main():
    nodes = [{'A': 1, 'B': 2, 'C': 3}, {'A': 4, 'B': 5, 'C': 6}, {'A': 7, 'B': 8, 'C': 9}]
    while True:
        ledger = simulate_consensus(nodes)
        print(ledger)
main()