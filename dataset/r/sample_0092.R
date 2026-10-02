analyze_network_connections <- function(connections, states, transitions) {
  current_state <- states[1]
  for (connection in connections) {
    for (transition in transitions) {
      if (transition[1] == current_state && transition[2] == connection) {
        current_state <- transition[3]
        break
      }
    }
  }
  return(current_state)
}

connections <- c('open', 'data', 'close')
states <- c('idle', 'active', 'closed')
transitions <- list(c('idle', 'open', 'active'), c('active', 'data', 'active'), c('active', 'close', 'closed'))
result <- analyze_network_connections(connections, states, transitions)
print(result)