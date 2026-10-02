ruby
require 'json'
require 'digest'

class Block
  attr_accessor :index, :data, :previous_hash, :hash

  def initialize(index, data, previous_hash)
    @index = index
    @data = data
    @previous_hash = previous_hash
    @hash = calculate_hash
  end

  def calculate_hash
    block_string = JSON.dump({ 'index' => @index, 'data' => @data, 'previous_hash' => @previous_hash }, sort_keys: true)
    Digest::SHA256.hexdigest(block_string)
  end
end

class Blockchain
  attr_accessor :chain

  def initialize
    @chain = [create_genesis_block]
  end

  def create_genesis_block
    Block.new(0, 'Genesis Block', '0')
  end

  def add_block(new_block)
    new_block.previous_hash = @chain.last.hash
    new_block.hash = new_block.calculate_hash
    @chain << new_block
  end

  def is_chain_valid
    (1...@chain.length).each do |i|
      current_block = @chain[i]
      previous_block = @chain[i - 1]
      return false if current_block.hash != current_block.calculate_hash
      return false if current_block.previous_hash != previous_block.hash
    end
    true
  end
end

def simulate_consensus_mechanics
  blockchain = Blockchain.new
  (1..9).each do |i|
    new_block_data = "Block #{i} Data"
    new_block = Block.new(i, new_block_data, '')
    blockchain.add_block(new_block)
    puts "Block #{i} added to the blockchain"
  end
  if blockchain.is_chain_valid
    puts 'Blockchain is valid.'
  else
    puts 'Blockchain is invalid.'
  end
end

simulate_consensus_mechanics