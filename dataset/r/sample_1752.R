FrameSequence <- setRefClass("FrameSequence",
                            fields = list(frame = "numeric", history = "list"),
                            methods = list(
                              initialize = function(initial_frame) {
                                .self$frame <- initial_frame
                                .self$history <- list()
                              },
                              update = function(new_frame) {
                                .self$history <<- c(.self$history, .self$frame)
                                .self$frame <<- new_frame
                              },
                              get_history = function() {
                                return(.self$history)
                              }
                            ))

Tracker <- setRefClass("Tracker",
                      fields = list(sequence = "FrameSequence"),
                      methods = list(
                        initialize = function(sequence) {
                          .self$sequence <<- sequence
                        },
                        observe = function(current_frame) {
                          .self$sequence$update(current_frame)
                        },
                        retrieve_history = function() {
                          return(.self$sequence$get_history())
                        }
                      ))

Processor <- setRefClass("Processor",
                        fields = list(tracker = "Tracker", frame = "numeric"),
                        methods = list(
                          initialize = function(tracker) {
                            .self$tracker <<- tracker
                            .self$frame <<- 0
                          },
                          process = function() {
                            while (TRUE) {
                              .self$frame <<- .self$frame + 1
                              .self$tracker$observe(.self$frame)
                            }
                          }
                        ))

main <- function() {
  initial_frame <- 0
  sequence <- new("FrameSequence", initial_frame = initial_frame)
  tracker <- new("Tracker", sequence = sequence)
  processor <- new("Processor", tracker = tracker)
  processor$process()
}

main()