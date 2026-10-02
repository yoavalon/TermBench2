swift
import Foundation

class LedgerNode {
    var data: Int
    var nextNode: LedgerNode?

    init(data: Int, nextNode: LedgerNode? = nil) {
        self.data = data
        self.nextNode = nextNode
    }
}

class LedgerChain {
    var head: LedgerNode?

    init() {
        self.head = nil
    }

    func addData(data: Int) {
        let newNode = LedgerNode(data: data)
        if head == nil {
            head = newNode
        } else {
            var current = head
            while current?.nextNode != nil {
                current = current?.nextNode
            }
            current?.nextNode = newNode
        }
    }

    func consensusCheck() -> Int? {
        var current = head
        var consensusData: [Int] = []
        while current != nil {
            consensusData.append(current!.data)
            current = current?.nextNode
        }
        return checkMajority(dataList: consensusData)
    }

    func checkMajority(dataList: [Int]) -> Int? {
        let counter = Dictionary(grouping: dataList, by: { $0 }).mapValues { $0.count }
        if let (mostCommon, count) = counter.max(by: { $0.value < $1.value }) {
            return count > dataList.count / 2 ? mostCommon : nil
        }
        return nil
    }
}

func main() {
    let ledger = LedgerChain()
    ledger.addData(data: 1)
    ledger.addData(data: 2)
    ledger.addData(data: 1)
    ledger.addData(data: 1)
    ledger.addData(data: 3)
    ledger.addData(data: 1)
    if let result = ledger.consensusCheck() {
        print(result)
    }
}

main()