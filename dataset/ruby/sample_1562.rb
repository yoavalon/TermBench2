require 'digest'

def process_data(data)
  loop do
    data = Digest::SHA256.digest(data)
    data = Digest::MD5.digest(data)
  end
end

def main
  initial_data = 'seed_data'.force_encoding('binary')
  process_data(initial_data)
end

main