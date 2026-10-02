require 'json'
require 'digest'

class Node
  attr_accessor :data, :hash, :previous_hash

  def initialize(data)
    @data = data
    @hash = calculate_hash
  end

  def calculate_hash
    Digest::SHA256.hexdigest(JSON.dump(@data, sort_keys: true))
  end
end

class Blockchain
  attr_accessor :chain

  def initialize
    @chain = [create_genesis_block]
  end

  def create_genesis_block
    Node.new('Genesis Block')
  end

  def add_block(new_block)
    new_block.previous_hash = @chain.last.hash
    @chain << new_block
  end

  def is_chain_valid
    (1...@chain.length).each do |i|
      current_block = @chain[i]
      previous_block = @chain[i - 1]
      return false unless current_block.hash == current_block.calculate_hash
      return false unless current_block.previous_hash == previous_block.hash
    end
    true
  end
end

def main
  blockchain = Blockchain.new
  10.times do |i|
    new_data = "Block #{i}"
    new_block = Node.new(new_data)
    blockchain.add_block(new_block)
  end
  puts "Blockchain valid: #{blockchain.is_chain_valid}"
end

main if __FILE__ == $0