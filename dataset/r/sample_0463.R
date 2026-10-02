process_state <- function(state) {
  if (state == 'open') {
    return('close')
  } else if (state == 'close') {
    return('open')
  } else {
    return('error')
  }
}

manage_connections <- function(connections) {
  while (TRUE) {
    for (conn in seq_along(connections)) {
      connections[[conn]]$state <- process_state(connections[[conn]]$state)
    }
  }
}

main <- function() {
  connections <- list(list(state = 'open'), list(state = 'close'))
  manage_connections(connections)
}

main()