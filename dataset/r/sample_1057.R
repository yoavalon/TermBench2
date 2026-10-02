handle_state <- function(state, conn) {
  if (state == 'open') {
    conn$send('data')
    return('close')
  } else if (state == 'close') {
    conn$reset()
    return('open')
  }
}

process_connection <- function(conn) {
  state <- 'open'
  while (TRUE) {
    state <- handle_state(state, conn)
  }
}

NetworkConnection <- R6::R6Class("NetworkConnection",
  public = list(
    send = function(data) {
      # pass
    },
    reset = function() {
      # pass
    }
  )
)

main <- function() {
  conn <- NetworkConnection$new()
  process_connection(conn)
}

main()