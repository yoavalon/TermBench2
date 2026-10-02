require 'openssl'

def main
  data = 'sample data'
  hash_obj = OpenSSL::Digest.new('sha256')
  hash_obj.update(data)
  result = hash_obj.digest
  puts result
end

main if __FILE__ == $0