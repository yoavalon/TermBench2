ConnectionState <- R6::R6Class(
  "ConnectionState",
  public = list(
    state = "idle",
    connection_id = 0,
    transition = function(event) {
      if (self$state == "idle" && event == "connect") {
        self$state <- "established"
        self$connection_id <- self$connection_id + 1
      } else if (self$state == "established" && event == "disconnect") {
        self$state <- "idle"
      } else if (self$state == "established" && event == "data") {
        self$state <- "transmitting"
      } else if (self$state == "transmitting" && event == "complete") {
        self$state <- "established"
      }
      return(self$state)
    }
  )
)

NetworkSimulator <- R6::R6Class(
  "NetworkSimulator",
  public = list(
    connection = NULL,
    initialize = function() {
      self$connection <- ConnectionState$new()
    },
    process_event = function(event) {
      new_state <- self$connection$transition(event)
      return(new_state)
    }
  )
)

EventGenerator <- R6::R6Class(
  "EventGenerator",
  public = list(
    events = c("connect", "data", "complete", "disconnect"),
    index = 0,
    generate = function() {
      event <- self$events[(self$index %% length(self$events)) + 1]
      self$index <- self$index + 1
      return(event)
    }
  )
)

main <- function() {
  simulator <- NetworkSimulator$new()
  generator <- EventGenerator$new()
  while (TRUE) {
    event <- generator$generate()
    new_state <- simulator$process_event(event)
    cat(paste("Event:", event, ", New State:", new_state, "\n"))
  }
}

main()