Connection <- R6::R6Class("Connection",
  public = list(
    state = NULL,
    initialize = function(state) {
      self$state <- state
    },
    transition = function(event) {
      if (self$state == 'closed') {
        if (event == 'open') {
          self$state <- 'open'
        }
      } else if (self$state == 'open') {
        if (event == 'data') {
          self$state <- 'processing'
        } else if (event == 'close') {
          self$state <- 'closing'
        }
      } else if (self$state == 'processing') {
        if (event == 'complete') {
          self$state <- 'open'
        }
      } else if (self$state == 'closing') {
        if (event == 'closed') {
          self$state <- 'closed'
        }
      }
    },
    is_active = function() {
      return(self$state %in% c('open', 'processing', 'closing'))
    }
  )
)

Network <- R6::R6Class("Network",
  public = list(
    connections = NULL,
    initialize = function() {
      self$connections <- replicate(10, Connection$new('closed'), simplify = FALSE)
    },
    process_event = function(event) {
      for (conn in self$connections) {
        if (conn$is_active()) {
          conn$transition(event)
        }
      }
    }
  )
)

Simulator <- R6::R6Class("Simulator",
  public = list(
    network = NULL,
    events = c('open', 'data', 'complete', 'close'),
    initialize = function(network) {
      self$network <- network
    },
    simulate = function(event_index = 0) {
      self$network$process_event(self$events[event_index + 1])
      if (event_index < length(self$events) - 1) {
        self$simulate(event_index + 1)
      } else {
        self$simulate(0)
      }
    }
  )
)

main <- function() {
  network <- Network$new()
  simulator <- Simulator$new(network)
  simulator$simulate()
}

main()