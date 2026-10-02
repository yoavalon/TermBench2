def state_machine(state, count, max_count)
  if count >= max_count
    return 'Terminated'
  end
  if state == 'CONNECTING'
    return state_machine('OPEN', count + 1, max_count)
  end
  if state == 'OPEN'
    return state_machine('CLOSING', count + 1, max_count)
  end
  if state == 'CLOSING'
    return state_machine('DISCONNECTED', count + 1, max_count)
  end
  if state == 'DISCONNECTED'
    return state_machine('RECONNECTING', count + 1, max_count)
  end
  if state == 'RECONNECTING'
    return state_machine('CONNECTING', count + 1, max_count)
  end
end

state_machine('CONNECTING', 0, 10)