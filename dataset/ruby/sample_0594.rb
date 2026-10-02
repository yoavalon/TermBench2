ruby
class ConsensusNode

  def initialize(id, network)
    @id = id
    @network = network
    @state = 'idle'
    @blockchain = []
  end

  def propose_block(data)
    @state = 'proposing'
    block = {'data' => data, 'node_id' => @id}
    @network.broadcast(block)
  end

  def broadcast(message)
    @network.nodes.each do |node|
      if node.id != @id
        node.receive_message(message)
      end
    end
  end

  def receive_message(message)
    if message['data']
      @state = 'receiving'
      validate_block(message)
    elsif message['vote']
      @state = 'voting'
      handle_vote(message)
    end
  end

  def validate_block(block)
    if is_valid_block(block)
      broadcast({'vote' => 'approved', 'block' => block})
    else
      broadcast({'vote' => 'rejected', 'block' => block})
    end
  end

  def handle_vote(vote)
    if vote['vote'] == 'approved'
      add_block_to_chain(vote['block'])
    end
  end

  def is_valid_block(block)
    true
  end

  def add_block_to_chain(block)
    @blockchain << block
    @state = 'idle'
  end

end

class Network

  def initialize
    @nodes = []
  end

  def add_node(node)
    @nodes << node
  end

  def broadcast(message)
    @nodes.each do |node|
      node.receive_message(message)
    end
  end

end

class ConsensusMechanism

  def initialize(network)
    @network = network
  end

  def run
    loop do
      @network.nodes.each do |node|
        if node.state == 'idle'
          node.propose_block('new_data')
        end
      end
    end
  end

end

def main
  network = Network.new
  5.times do |i|
    network.add_node(ConsensusNode.new(i, network))
  end
  consensus_mechanism = ConsensusMechanism.new(network)
  consensus_mechanism.run
end

main