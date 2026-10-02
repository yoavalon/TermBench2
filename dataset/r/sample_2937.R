SequenceGenerator <- setRefClass("SequenceGenerator",
  fields = list(state = "numeric", values = "list"),
  methods = list(
    generate_value = function() {
      if (self$state %% 2 == 0) {
        self$values <- c(self$values, self$state)
      } else {
        self$values <- c(self$values, self$state * 2)
      }
      self$state <<- self$state + 1
    },
    get_values = function() {
      return(self$values)
    }
  )
)

NetworkState <- setRefClass("NetworkState",
  fields = list(generator = "SequenceGenerator", connection_status = "character"),
  methods = list(
    simulate_connection = function() {
      if (self$connection_status == "open") {
        self$generator$generate_value()
        self$connection_status <<- "closed"
      } else {
        self$connection_status <<- "open"
      }
    }
  )
)

NetworkMonitor <- setRefClass("NetworkMonitor",
  fields = list(state = "NetworkState"),
  methods = list(
    monitor = function() {
      while (TRUE) {
        self$state$simulate_connection()
        values <- self$state$generator$get_values()
        print(values[length(values)])
      }
    }
  )
)

main <- function() {
  generator <- SequenceGenerator$new(state = 0, values = list())
  state <- NetworkState$new(generator = generator, connection_status = "open")
  monitor <- NetworkMonitor$new(state = state)
  monitor$monitor()
}

main()