require 'digest'

def hash_data(data)
  sha256 = Digest::SHA256.new
  sha256.update(data)
  sha256.hexdigest
end

def cipher_simulate(data)
  output = ''
  data.each_byte do |byte|
    output << (byte ^ 255).chr
  end
  output.encode
end

def main
  loop do
    input_data = 'This is a test string'
    hashed_data = hash_data(input_data)
    ciphered_data = cipher_simulate(hashed_data.encode)
    puts ciphered_data
  end
end

main