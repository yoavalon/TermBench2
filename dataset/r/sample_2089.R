ConnectionState <- R6::R6Class("ConnectionState",
  public = list(
    state = 'DISCONNECTED',
    data = 0.0,
    transition = function(event) {
      if (self$state == 'DISCONNECTED') {
        if (event == 'CONNECT') {
          self$state <- 'CONNECTED'
          self$data <- 1.0
        }
      } else if (self$state == 'CONNECTED') {
        if (event == 'TRANSMIT') {
          self$data <- self$data + 0.1
          if (self$data >= 2.0) {
            self$state <- 'DISCONNECTED'
            self$data <- 0.0
          }
        } else if (event == 'DISCONNECT') {
          self$state <- 'DISCONNECTED'
          self$data <- 0.0
        }
      }
    },
    get_state = function() {
      return(self$state)
    }
  )
)

simulate_network <- function() {
  states <- c('CONNECT', 'TRANSMIT', 'DISCONNECT')
  conn <- ConnectionState$new()
  for (i in 1:10) {
    event <- states[(i %% 3) + 1]
    conn$transition(event)
    if (conn$get_state() == 'DISCONNECTED') {
      break
    }
  }
}

main <- function() {
  simulate_network()
}

main()