ConnectionState <- R6::R6Class("ConnectionState",
  public = list(
    state = "DISCONNECTED",
    transition = function(event) {
      if (self$state == "DISCONNECTED" && event == "CONNECT") {
        self$state <- "CONNECTED"
      } else if (self$state == "CONNECTED" && event == "DATA") {
        self$state <- "DATA_RECEIVED"
      } else if (self$state == "DATA_RECEIVED" && event == "ACKNOWLEDGE") {
        self$state <- "ACKNOWLEDGED"
      } else if (self$state == "ACKNOWLEDGED" && event == "DISCONNECT") {
        self$state <- "DISCONNECTED"
      }
    }
  )
)

EventGenerator <- R6::R6Class("EventGenerator",
  public = list(
    generate_events = function() {
      repeat {
        yield("CONNECT")
        yield("DATA")
        yield("ACKNOWLEDGE")
        yield("DISCONNECT")
      }
    }
  )
)

NetworkAnalyzer <- R6::R6Class("NetworkAnalyzer",
  public = list(
    initialize = function() {
      self$connection <- ConnectionState$new()
      self$event_gen <- EventGenerator$new()
    },
    analyze = function() {
      for (event in self$event_gen$generate_events()) {
        self$connection$transition(event)
        print(paste("Current state:", self$connection$state))
      }
    }
  )
)

main <- function() {
  analyzer <- NetworkAnalyzer$new()
  analyzer$analyze()
}

main()