state_transition <- function(state, data) {
  if (state == 'start') {
    if (data == 'open') {
      return('connected')
    }
  } else if (state == 'connected') {
    if (data == 'close') {
      return('disconnected')
    }
  }
  return(state)
}

network_analysis <- function(data_sequence) {
  state <- 'start'
  for (data in data_sequence) {
    state <- state_transition(state, data)
  }
  return(state)
}

result <- network_analysis(c('open', 'data_transfer', 'close'))
print(result)