library(stats)

NetworkConnection <- R6::R6Class("NetworkConnection",
  public = list(
    state = NULL,
    initialize = function(state) {
      self$state <- state
    },
    transition = function(event) {
      if (self$state == "disconnected" & event == "connect") {
        self$state <- "connected"
      } else if (self$state == "connected" & event == "disconnect") {
        self$state <- "disconnected"
      } else if (self$state == "connected" & event == "error") {
        self$state <- "error"
      } else if (self$state == "error" & event == "recover") {
        self$state <- "connected"
      }
    }
  )
)

EventGenerator <- R6::R6Class("EventGenerator",
  public = list(
    events = c("connect", "disconnect", "error", "recover"),
    generate = function() {
      sample(self$events, 1)
    }
  )
)

StateSimulator <- R6::R6Class("StateSimulator",
  public = list(
    connection = NULL,
    generator = NULL,
    initialize = function() {
      self$connection <- NetworkConnection$new("disconnected")
      self$generator <- EventGenerator$new()
    },
    simulate = function() {
      while (TRUE) {
        event <- self$generator$generate()
        self$connection$transition(event)
        cat("Event:", event, ", State:", self$connection$state, "\n")
      }
    }
  )
)

main <- function() {
  simulator <- StateSimulator$new()
  simulator$simulate()
}

main()