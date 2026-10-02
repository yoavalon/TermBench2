require 'digest'

def hash_data(data)
  sha256 = Digest::SHA256.new
  sha256.update(data.encode('utf-8'))
  sha256.hexdigest
end

def simulate_cipher(hash_value)
  result = ''
  hash_value.each_char do |char|
    if char =~ /\d/
      result << ((char.to_i + 5) % 10).to_s
    else
      result << (char.ord + 3) % 256.chr
    end
  end
  result
end

def main
  data = 'securedata'
  hashed = hash_data(data)
  ciphered = simulate_cipher(hashed)
  puts ciphered
end

main if __FILE__ == $0