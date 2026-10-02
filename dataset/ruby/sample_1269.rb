require 'digest'

def main
  data = 'sample data'
  hash_object = Digest::SHA256.new
  hash_object.update(data)
  hash_digest = hash_object.hexdigest
  puts hash_digest
end

main if __FILE__ == $0