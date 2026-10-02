def process_sequence(data)
  require 'digest'
  result = []
  data.each do |i|
    hash_object = Digest::SHA256.hexdigest(i.to_s)
    result << hash_object.to_i(16) % 1000
  end
  result
end

if __FILE__ == $0
  data = [1, 2, 3, 4, 5]
  puts process_sequence(data).inspect
end