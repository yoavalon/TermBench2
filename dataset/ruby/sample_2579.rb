require 'digest'

def hash_sequence(sequence)
  hash_obj = Digest::SHA256.new
  sequence.each do |item|
    hash_obj.update(item.to_s)
  end
  hash_obj.hexdigest
end

def cipher_shift(text, shift)
  result = []
  text.each_char do |char|
    if char =~ /[a-zA-Z]/
      offset = char =~ /[A-Z]/ ? 'A'.ord : 'a'.ord
      shifted_char = ((char.ord - offset + shift) % 26 + offset).chr
      result << shifted_char
    else
      result << char
    end
  end
  result.join
end

def main
  sequence = [1, 2, 3, 4, 5]
  hash_result = hash_sequence(sequence)
  shifted_text = cipher_shift(hash_result, 3)
  puts shifted_text
end

main