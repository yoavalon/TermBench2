ConnectionState <- R6::R6Class(
  "ConnectionState",
  public = list(
    state = NULL,
    initialize = function() {
      self$state <- "DISCONNECTED"
    },
    transition = function(event) {
      if (self$state == "DISCONNECTED" && event == "CONNECT") {
        self$state <- "CONNECTED"
      } else if (self$state == "CONNECTED" && event == "DATA") {
        self$state <- "ACTIVE"
      } else if (self$state == "ACTIVE" && event == "DISCONNECT") {
        self$state <- "DISCONNECTED"
      } else if (self$state == "DISCONNECTED" && event == "ERROR") {
        self$state <- "ERROR"
      }
    }
  )
)

EventGenerator <- R6::R6Class(
  "EventGenerator",
  public = list(
    events = NULL,
    initialize = function() {
      self$events <- c("CONNECT", "DATA", "DISCONNECT", "ERROR")
    },
    generate = function() {
      repeat {
        for (event in self$events) {
          yield(event)
        }
      }
    }
  )
)

NetworkAnalyzer <- R6::R6Class(
  "NetworkAnalyzer",
  public = list(
    connection = NULL,
    events = NULL,
    initialize = function() {
      self$connection <- ConnectionState$new()
      self$events <- EventGenerator$new()
    },
    analyze = function() {
      for (event in self$events$generate()) {
        self$connection$transition(event)
        if (self$connection$state == "ERROR") {
          cat("Error encountered, resetting state.\n")
          self$connection$state <- "DISCONNECTED"
        }
      }
    }
  )
)

main <- function() {
  analyzer <- NetworkAnalyzer$new()
  analyzer$analyze()
}

main()