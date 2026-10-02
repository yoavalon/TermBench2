NetworkConnection <- R6::R6Class("NetworkConnection",
  public = list(
    state = NULL,
    initialize = function(state) {
      self$state <- state
    },
    transition = function(event) {
      if (self$state == 'closed') {
        if (event == 'open') {
          self$state <- 'open'
          self$transition(event)
        } else if (event == 'listen') {
          self$state <- 'listening'
          self$transition(event)
        }
      } else if (self$state == 'open') {
        if (event == 'close') {
          self$state <- 'closed'
          self$transition(event)
        } else if (event == 'send') {
          self$state <- 'sending'
          self$transition(event)
        }
      } else if (self$state == 'listening') {
        if (event == 'accept') {
          self$state <- 'open'
          self$transition(event)
        }
      } else if (self$state == 'sending') {
        if (event == 'complete') {
          self$state <- 'open'
          self$transition(event)
        }
      }
    }
  )
)

event_generator <- function() {
  events <- c('open', 'listen', 'accept', 'send', 'complete', 'close')
  while (TRUE) {
    for (event in events) {
      yield(event)
    }
  }
}

main <- function() {
  connection <- NetworkConnection$new('closed')
  for (event in event_generator()) {
    connection$transition(event)
  }
}

main()