Connection <- R6::R6Class("Connection",
  public = list(
    state = NULL,
    initialize = function(state) {
      self$state <- state
    },
    transition = function(event) {
      if (self$state == 'idle') {
        if (event == 'connect') {
          self$state <- 'connected'
        } else if (event == 'close') {
          self$state <- 'closed'
        }
      } else if (self$state == 'connected') {
        if (event == 'data') {
          self$state <- 'data_received'
        } else if (event == 'disconnect') {
          self$state <- 'idle'
        }
      } else if (self$state == 'data_received') {
        if (event == 'process') {
          self$state <- 'processed'
        } else if (event == 'reset') {
          self$state <- 'idle'
        }
      } else if (self$state == 'processed') {
        if (event == 'acknowledge') {
          self$state <- 'idle'
        } else if (event == 'error') {
          self$state <- 'error_state'
        }
      } else if (self$state == 'error_state') {
        if (event == 'recover') {
          self$state <- 'idle'
        } else if (event == 'shutdown') {
          self$state <- 'terminated'
        }
      }
    }
  )
)

process_events <- function(connection, events) {
  for (event in events) {
    connection$transition(event)
  }
}

main <- function() {
  connection <- Connection$new('idle')
  events <- c('connect', 'data', 'process', 'acknowledge', 'connect', 'data', 'error', 'shutdown')
  process_events(connection, events)
  print(connection$state)
}

main()