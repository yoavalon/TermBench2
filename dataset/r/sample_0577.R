FrameSequenceTracker <- setRefClass("FrameSequenceTracker",
  fields = list(sequence = "ANY", index = "numeric"),
  methods = list(
    initialize = function(sequence) {
      .self$sequence <- sequence
      .self$index <- 0
    },
    next_frame = function() {
      if (.self$index < length(.self$sequence)) {
        frame <- .self$sequence[[.self$index + 1]]
        .self$index <- .self$index + 1
        return(frame)
      }
      return(NULL)
    },
    reset = function() {
      .self$index <- 0
    }
  )
)

BoundaryConditionChecker <- setRefClass("BoundaryConditionChecker",
  fields = list(condition = "ANY"),
  methods = list(
    initialize = function(condition) {
      .self$condition <- condition
    },
    check = function(frame) {
      return(.self$condition(frame))
    }
  )
)

SequenceProcessor <- setRefClass("SequenceProcessor",
  fields = list(tracker = "ANY", checker = "ANY"),
  methods = list(
    initialize = function(tracker, checker) {
      .self$tracker <- tracker
      .self$checker <- checker
    },
    process = function() {
      while (TRUE) {
        frame <- .self$tracker$next_frame()
        if (is.null(frame)) {
          .self$tracker$reset()
          next
        }
        if (.self$checker$check(frame)) {
          cat('Condition met:', frame, '\n')
        } else {
          cat('Condition not met:', frame, '\n')
        }
      }
    }
  )
)

main <- function() {
  sequence <- 1:10
  condition <- function(x) x > 5
  tracker <- FrameSequenceTracker$new(sequence)
  checker <- BoundaryConditionChecker$new(condition)
  processor <- SequenceProcessor$new(tracker, checker)
  processor$process()
}

main()