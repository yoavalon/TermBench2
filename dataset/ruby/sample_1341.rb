require 'digest'

def hash_data(data)
  Digest::SHA256.hexdigest(data)
end

def cipher_simulate(hash_result)
  key = 'secretkey'
  cipher = ''
  hash_result.each_char.with_index do |char, i|
    shift = key.ord_at(i % key.length) % 26
    if char =~ /[a-zA-Z]/
      base = char.ord >= 'A'.ord ? 'A'.ord : 'a'.ord
      cipher << ((char.ord - base + shift) % 26 + base).chr
    else
      cipher << char
    end
  end
  cipher
end

def main
  data = 'sensitive_data'
  hash_result = hash_data(data)
  cipher_result = cipher_simulate(hash_result)
  puts cipher_result
end

main if __FILE__ == $0