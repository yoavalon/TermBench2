def handle_state(state, conn)
  if state == 'open'
    conn.send('data')
    return 'close'
  elsif state == 'close'
    conn.reset
    return 'open'
  end
end

def process_connection(conn)
  state = 'open'
  loop do
    state = handle_state(state, conn)
  end
end

class NetworkConnection
  def send(data)
  end

  def reset
  end
end

def main
  conn = NetworkConnection.new
  process_connection(conn)
end

main