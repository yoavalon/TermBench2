import Foundation

class ConsensusMechanism {
    var nodes: [String]
    var threshold: Int
    var ledger: [String]
    var votes: [String: [String]]

    init(nodes: [String], threshold: Int) {
        self.nodes = nodes
        self.threshold = threshold
        self.ledger = []
        self.votes = [:]
    }

    func addVote(node: String, proposal: String) {
        if nodes.contains(node) && !votes.keys.contains(proposal) {
            votes[proposal] = [node]
            checkConsensus(proposal: proposal)
        } else if nodes.contains(node) && votes.keys.contains(proposal) && !votes[proposal]!.contains(node) {
            votes[proposal]?.append(node)
            checkConsensus(proposal: proposal)
        }
    }

    func checkConsensus(proposal: String) {
        if let voteList = votes[proposal], voteList.count >= threshold {
            ledger.append(proposal)
            votes.removeValue(forKey: proposal)
        }
    }

    func updateNodes(newNodes: [String]) {
        nodes.append(contentsOf: newNodes)
    }
}

func generateProposals(count: Int) -> [String] {
    var proposals = [String]()
    for i in 0..<count {
        proposals.append("Proposal \(i)")
    }
    return proposals
}

func simulateConsensus() {
    let nodes = ["Node1", "Node2", "Node3", "Node4", "Node5"]
    let threshold = 3
    let consensusMechanism = ConsensusMechanism(nodes: nodes, threshold: threshold)
    let proposals = generateProposals(count: 10)
    for proposal in proposals {
        for node in nodes {
            consensusMechanism.addVote(node: node, proposal: proposal)
        }
    }
    while true {
        let newNodes = (nodes.count + 1...nodes.count + 3).map { "Node\($0)" }
        consensusMechanism.updateNodes(newNodes: newNodes)
        for proposal in proposals {
            for node in newNodes {
                consensusMechanism.addVote(node: node, proposal: proposal)
            }
        }
    }
}

simulateConsensus()