StateMachine <- setRefClass("StateMachine",
  fields = list(
    state = "character",
    sequence = "list"
  ),
  methods = list(
    initialize = function() {
      .self$state <- "idle"
      .self$sequence <- list()
    },
    transition = function(event) {
      if (.self$state == "idle") {
        if (event == "connect") {
          .self$state <<- "connected"
          .self$sequence <<- c(.self$sequence, 0)
        }
      } else if (.self$state == "connected") {
        if (event == "data") {
          .self$sequence <<- c(.self$sequence, 1)
        } else if (event == "disconnect") {
          .self$state <<- "idle"
          .self$sequence <<- c(.self$sequence, 2)
        }
      }
      return(.self$sequence)
    }
  )
)

SequenceAnalyzer <- setRefClass("SequenceAnalyzer",
  fields = list(
    machine = "StateMachine"
  ),
  methods = list(
    initialize = function(machine) {
      .self$machine <<- machine
    },
    analyze = function() {
      while (TRUE) {
        sequence <- .self$machine$transition("data")
        if (length(sequence) > 10) {
          .self$reset_sequence()
        }
      }
    },
    reset_sequence = function() {
      .self$machine$sequence <<- list()
    }
  )
)

main <- function() {
  machine <- new("StateMachine")
  analyzer <- new("SequenceAnalyzer", machine = machine)
  while (TRUE) {
    machine$transition("connect")
    analyzer$analyze()
  }
}

main()