require 'digest'

def hash_and_cipher(data)
  hash_obj = Digest::SHA256.hexdigest(data)
  cipher_text = hash_obj.chars.map { |c| ((c.ord + 3) % 256).chr }.join
  return cipher_text
end

def main
  data = 'sensitive information'
  result = hash_and_cipher(data)
  puts result
end

main