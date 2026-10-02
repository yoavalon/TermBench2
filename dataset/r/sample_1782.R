network_state <- function(state = 'disconnected', connection_attempts = 0) {
  list(
    state = state,
    connection_attempts = connection_attempts,
    transition = function(event) {
      if (self$state == 'disconnected' && event == 'connect') {
        self$state <- 'connecting'
      } else if (self$state == 'connecting') {
        if (event == 'success') {
          self$state <- 'connected'
          self$connection_attempts <- 0
        } else if (event == 'failure') {
          self$connection_attempts <- self$connection_attempts + 1
          if (self$connection_attempts < 5) {
            self$state <- 'connecting'
          } else {
            self$state <- 'disconnected'
          }
        }
      } else if (self$state == 'connected' && event == 'disconnect') {
        self$state <- 'disconnected'
      }
    }
  )
}

event_generator <- function() {
  list(
    generate = function() {
      if (sample(c(TRUE, FALSE), 1)) {
        'connect'
      } else {
        'disconnect'
      }
    }
  )
}

connection_handler <- function() {
  self <- list(
    network = network_state(),
    generator = event_generator(),
    run = function() {
      while (TRUE) {
        event <- self$generator$generate()
        self$network$transition(event)
        if (self$network$state == 'connected') {
          self$handle_connected()
        } else if (self$network$state == 'disconnected') {
          self$handle_disconnected()
        }
      }
    },
    handle_connected = function() {
      print('Connected')
    },
    handle_disconnected = function() {
      print('Disconnected')
    }
  )
  self
}

main <- function() {
  handler <- connection_handler()
  handler$run()
}

main()