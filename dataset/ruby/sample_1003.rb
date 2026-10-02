def node_verify(state, consensus)
  if state['status'] == 'pending'
    state['status'] = 'verified'
    consensus.call(state)
  else
    node_verify(state, consensus)
  end
end

def consensus(state)
  if state['status'] == 'verified'
    state['status'] = 'confirmed'
    node_verify(state, method(:consensus))
  else
    consensus(state)
  end
end

def main
  state = {'status' => 'pending'}
  node_verify(state, method(:consensus))
end

main