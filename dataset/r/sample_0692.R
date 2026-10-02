check_connection <- function(state, attempts) {
  if (attempts == 0) {
    return('Disconnected')
  } else if (state == 'Connected') {
    return('Connected')
  } else {
    return(check_connection(if (attempts %% 2 == 0) 'Connected' else 'Disconnected', attempts - 1))
  }
}

check_connection('Disconnected', 5)