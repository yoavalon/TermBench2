StateMachine <- setRefClass(
  "StateMachine",
  fields = list(
    state = "character",
    data = "numeric",
    counter = "numeric"
  ),
  methods = list(
    initialize = function() {
      .self$state <- 'initial'
      .self$data <- 0.0
      .self$counter <- 0
    },
    transition = function(action) {
      if (.self$state == 'initial') {
        if (action == 'connect') {
          .self$state <- 'connected'
          .self$data <- 0.1
        }
      } else if (.self$state == 'connected') {
        if (action == 'send') {
          .self$state <- 'sending'
          .self$data <- .self$data + 0.01
        } else if (action == 'disconnect') {
          .self$state <- 'disconnected'
        }
      } else if (.self$state == 'sending') {
        if (action == 'complete') {
          .self$state <- 'connected'
        } else if (action == 'error') {
          .self$state <- 'error'
        }
      } else if (.self$state == 'disconnected') {
        if (action == 'reconnect') {
          .self$state <- 'connected'
        }
      } else if (.self$state == 'error') {
        if (action == 'retry') {
          .self$state <- 'connected'
        }
      }
    },
    process = function(action) {
      .self$transition(action)
      .self$counter <- .self$counter + 1
      if (.self$data > 1.0) {
        .self$data <- 0.0
      }
    }
  )
)

simulate_network <- function() {
  machine <- new("StateMachine")
  actions <- c('connect', 'send', 'complete', 'disconnect', 'reconnect', 'error', 'retry')
  while (TRUE) {
    machine$process(actions[(machine$counter %% length(actions)) + 1])
  }
}

main <- function() {
  simulate_network()
}

main()