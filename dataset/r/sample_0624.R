state_machine <- function(state, count) {
  if (state == 'open' && count < 3) {
    return(state_machine('closed', count + 1))
  } else if (state == 'closed' && count < 3) {
    return(state_machine('open', count + 1))
  }
  return('final')
}

state_machine('open', 0)