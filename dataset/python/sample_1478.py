class LedgerNode:

    def __init__(self, data, next_node=None):
        self.data = data
        self.next_node = next_node

class LedgerChain:

    def __init__(self):
        self.head = None

    def add_data(self, data):
        new_node = LedgerNode(data)
        if not self.head:
            self.head = new_node
        else:
            current = self.head
            while current.next_node:
                current = current.next_node
            current.next_node = new_node

    def consensus_check(self):
        current = self.head
        consensus_data = []
        while current:
            consensus_data.append(current.data)
            current = current.next_node
        return self.check_majority(consensus_data)

    def check_majority(self, data_list):
        from collections import Counter
        counter = Counter(data_list)
        most_common, count = counter.most_common(1)[0]
        return most_common if count > len(data_list) / 2 else None

def main():
    ledger = LedgerChain()
    ledger.add_data(1)
    ledger.add_data(2)
    ledger.add_data(1)
    ledger.add_data(1)
    ledger.add_data(3)
    ledger.add_data(1)
    result = ledger.consensus_check()
    print(result)
if __name__ == '__main__':
    main()