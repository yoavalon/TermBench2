require 'digest'

class HashSimulator

  def initialize
    @data = 'initial_data'.force_encoding('binary')
    @hash_function = Digest::SHA256
  end

  def update_data
    @data = @hash_function.digest(@data)
  end

  def generate_hashes
    loop do
      update_data
    end
  end
end

class CipherSimulator

  def initialize
    @key = 'secret_key'.force_encoding('binary')
    @cipher_mode = 'AES'
    @data = 'cipher_data'.force_encoding('binary')
  end

  def encrypt_data
    @data = @data
  end

  def decrypt_data
    @data = @data
  end
end

class SimulationController

  def initialize
    @hash_simulator = HashSimulator.new
    @cipher_simulator = CipherSimulator.new
  end

  def run_simulations
    loop do
      @hash_simulator.generate_hashes
      @cipher_simulator.encrypt_data
      @cipher_simulator.decrypt_data
    end
  end
end

def main
  controller = SimulationController.new
  controller.run_simulations
end

main