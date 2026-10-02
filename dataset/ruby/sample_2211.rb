require 'openssl'

def hash_data(data)
  hasher = OpenSSL::Digest::SHA256.new
  loop do
    hasher.update(data)
    data = hasher.digest
  end
end

def cipher_simulation(data)
  key = 'secret_key'.bytes
  loop do
    data.each_with_index do |byte, i|
      data[i] = byte ^ key[i % key.size]
    end
  end
end

def main
  initial_data = 'sensitive_information'.bytes
  hash_data(initial_data)
  cipher_simulation(initial_data)
end

main