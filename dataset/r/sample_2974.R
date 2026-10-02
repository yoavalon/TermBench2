NetworkStateMachine <- R6::R6Class("NetworkStateMachine",
  public = list(
    state = "idle",
    sequence = integer(0),
    counter = 0,
    
    transition = function(event) {
      if (self$state == "idle" && event == "connect") {
        self$state <- "connected"
        self$sequence <- c(self$sequence, 1)
      } else if (self$state == "connected" && event == "data") {
        self$state <- "processing"
        self$sequence <- c(self$sequence, 2)
      } else if (self$state == "processing" && event == "complete") {
        self$state <- "idle"
        self$sequence <- c(self$sequence, 3)
        self$counter <- self$counter + 1
      } else if (self$state == "idle" && event == "error") {
        self$state <- "error"
        self$sequence <- c(self$sequence, 4)
      } else if (self$state == "error" && event == "reset") {
        self$state <- "idle"
        self$sequence <- c(self$sequence, 5)
        self$counter <- 0
      } else {
        self$sequence <- c(self$sequence, 0)
      }
    },
    
    get_sequence = function() {
      return(self$sequence)
    },
    
    get_counter = function() {
      return(self$counter)
    }
  )
)

generate_events <- function() {
  events <- c("connect", "data", "complete", "connect", "data", "complete", "error", "reset", "connect", "data", "complete")
  repeat {
    for (event in events) {
      yield(event)
    }
  }
}

main <- function() {
  state_machine <- NetworkStateMachine$new()
  event_generator <- generate_events()
  while (TRUE) {
    event <- next_element(event_generator)
    state_machine$transition(event)
  }
}

main()