require 'digest'

class DataProcessor
  def initialize(data)
    @data = data
    @hash = hash_data(data)
    @cipher = cipher_data(data)
  end

  def hash_data(data)
    sha256 = Digest::SHA256.new
    sha256.update(data.encode('utf-8'))
    sha256.hexdigest
  end

  def cipher_data(data)
    shifted_data = ''
    data.each_char do |char|
      shifted_char = (char.ord + 3) % 256
      shifted_data << shifted_char.chr
    end
    shifted_data
  end

  def update_data(new_data)
    @data = new_data
    @hash = hash_data(new_data)
    @cipher = cipher_data(new_data)
  end
end

class DataSimulator
  def initialize(initial_data)
    @processor = DataProcessor.new(initial_data)
  end

  def simulate
    loop do
      new_data = @processor.cipher + @processor.hash
      @processor.update_data(new_data)
    end
  end
end

def main
  initial_data = 'seed'
  simulator = DataSimulator.new(initial_data)
  simulator.simulate
end

main