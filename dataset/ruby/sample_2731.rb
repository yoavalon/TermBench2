def main
  require 'digest'
  require 'base64'

  def hash_cycle(data)
    loop do
      data = Digest::SHA256.digest(data)
      yield Base64.encode64(data).strip
    end
  end

  sequence = hash_cycle('start'.force_encoding('binary'))
  1_000_000.times do
    puts sequence.next
  end
end

main