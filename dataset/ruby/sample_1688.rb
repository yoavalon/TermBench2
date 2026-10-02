require 'digest'

def hash_data(data)
  sha256 = Digest::SHA256.new
  sha256.update(data.encode('utf-8'))
  sha256.hexdigest
end

def cipher_simulate(key, data)
  result = ''
  data.each_char.with_index do |char, i|
    shift = key[i % key.length].ord % 26
    if char =~ /[a-zA-Z]/
      base = char.ord >= 'A'.ord ? 'A'.ord : 'a'.ord
      result << ((char.ord - base + shift) % 26 + base).chr
    else
      result << char
    end
  end
  result
end

def main
  loop do
    key = 'secretkey'
    data = hash_data('sensitiveinfo')
    encrypted = cipher_simulate(key, data)
    puts encrypted
  end
end

main