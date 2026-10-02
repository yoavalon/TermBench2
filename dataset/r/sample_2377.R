NetworkState <- R6::R6Class("NetworkState",
  public = list(
    connection = FALSE,
    data = 0.0,
    threshold = 0.5,
    connect = function() {
      self$connection <- TRUE
      self$data <- 0.1
    },
    disconnect = function() {
      self$connection <- FALSE
      self$data <- 0.0
    },
    transmit = function() {
      if (self$connection) {
        self$data <- self$data + 0.01
        if (self$data >= self$threshold) {
          self$disconnect()
        }
      }
    }
  )
)

NetworkMonitor <- R6::R6Class("NetworkMonitor",
  public = list(
    state = NULL,
    initialize = function() {
      self$state <- NetworkState$new()
    },
    observe = function() {
      if (!self$state$connection) {
        self$state$connect()
      } else {
        self$state$transmit()
      }
    }
  )
)

NetworkAnalyzer <- R6::R6Class("NetworkAnalyzer",
  public = list(
    monitor = NULL,
    initialize = function(monitor) {
      self$monitor <- monitor
    },
    analyze = function() {
      while (TRUE) {
        self$monitor$observe()
      }
    }
  )
)

main <- function() {
  monitor <- NetworkMonitor$new()
  analyzer <- NetworkAnalyzer$new(monitor)
  analyzer$analyze()
}

main()