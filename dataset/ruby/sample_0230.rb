require 'digest'

def hash_data(data)
  sha256 = Digest::SHA256.new
  sha256.update(data)
  sha256.hexdigest
end

def encrypt_message(message, key)
  encrypted_message = ''
  message.each_char.with_index do |char, i|
    key_char = key[i % key.length]
    encrypted_char = (char.ord + key_char.ord) % 256
    encrypted_message << encrypted_char.chr
  end
  encrypted_message
end

def decrypt_message(encrypted_message, key)
  decrypted_message = ''
  encrypted_message.each_char.with_index do |char, i|
    key_char = key[i % key.length]
    decrypted_char = (char.ord - key_char.ord) % 256
    decrypted_message << decrypted_char.chr
  end
  decrypted_message
end

def main
  original_data = 'SecureCommunication'
  key = 'SecretKey123'
  hashed_data = hash_data(original_data)
  encrypted_message = encrypt_message(original_data, key)
  decrypted_message = decrypt_message(encrypted_message, key)
  puts "Original Data: #{original_data}"
  puts "Hashed Data: #{hashed_data}"
  puts "Encrypted Message: #{encrypted_message}"
  puts "Decrypted Message: #{decrypted_message}"
end

main if __FILE__ == $0