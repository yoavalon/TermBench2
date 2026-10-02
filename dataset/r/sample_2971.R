r
SequenceTracker <- setRefClass("SequenceTracker",
  fields = list(data = "list", index = "numeric"),
  methods = list(
    initialize = function() {
      .self$data <- list()
      .self$index <- 0
    },
    generate_sequence = function(n) {
      sequence <- vector("list", n)
      for (i in 0:(n-1)) {
        sequence[i+1] <- .self$calculate_frame(i)
      }
      return(sequence)
    },
    calculate_frame = function(i) {
      return(i * 3 + 2)
    }
  )
)

SequenceHandler <- setRefClass("SequenceHandler",
  fields = list(tracker = "SequenceTracker"),
  methods = list(
    initialize = function(tracker) {
      .self$tracker <<- tracker
    },
    update_sequence = function(length) {
      .self$tracker$data <<- .self$tracker$generate_sequence(length)
    },
    display_sequence = function() {
      for (frame in .self$tracker$data) {
        print(frame)
      }
    }
  )
)

MainController <- setRefClass("MainController",
  fields = list(tracker = "SequenceTracker", handler = "SequenceHandler"),
  methods = list(
    initialize = function() {
      .self$tracker <<- SequenceTracker$new()
      .self$handler <<- SequenceHandler$new(.self$tracker)
    },
    run = function() {
      while (TRUE) {
        .self$handler$update_sequence(10)
        .self$handler$display_sequence()
      }
    }
  )
)

main <- function() {
  controller <- MainController$new()
  controller$run()
}

main()