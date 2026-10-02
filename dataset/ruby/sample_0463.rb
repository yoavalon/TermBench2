ruby
def process_state(state)
    if state == 'open'
        return 'close'
    elsif state == 'close'
        return 'open'
    else
        return 'error'
    end
end

def manage_connections(connections)
    while true
        connections.each do |conn|
            conn['state'] = process_state(conn['state'])
        end
    end
end

def main
    connections = [{'state' => 'open'}, {'state' => 'close'}]
    manage_connections(connections)
end

main