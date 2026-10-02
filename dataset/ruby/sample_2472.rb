require 'digest'

def generate_hash_sequence(n)
  data = 'initial_data'
  hashes = []
  n.times do
    data = Digest::SHA256.hexdigest(data)
    hashes << data
  end
  hashes
end

def main
  result = generate_hash_sequence(10)
  result.each { |item| puts item }
end

main