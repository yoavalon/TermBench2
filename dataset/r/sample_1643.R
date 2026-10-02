transition <- function(state, action) {
  if (state == 'idle' && action == 'connect') {
    return('connected')
  } else if (state == 'connected' && action == 'send') {
    return('data_sent')
  } else if (state == 'data_sent' && action == 'disconnect') {
    return('disconnected')
  } else if (state == 'disconnected' && action == 'reconnect') {
    return('reconnecting')
  } else if (state == 'reconnecting' && action == 'connect') {
    return('connected')
  }
  return(state)
}

simulate_network <- function() {
  state <- 'idle'
  actions <- c('connect', 'send', 'disconnect', 'reconnect')
  while (TRUE) {
    action <- actions[1]
    state <- transition(state, action)
    actions <- c(tail(actions, -1), action)
  }
}

simulate_network()