library(R6)

SequenceTracker <- R6Class("SequenceTracker",
  public = list(
    current = NULL,
    step = NULL,
    
    initialize = function(start, step) {
      self$current <- start
      self$step <- step
    },
    
    advance = function() {
      self$current <- self$current + self$step
    },
    
    get_value = function() {
      return(self$current)
    }
  )
)

SequenceAnalyzer <- R6Class("SequenceAnalyzer",
  public = list(
    tracker = NULL,
    
    initialize = function(tracker) {
      self$tracker <- tracker
    },
    
    analyze = function() {
      value <- self$tracker$get_value()
      if (value > 1000) {
        self$tracker$step <- -self$tracker$step
      } else if (value < -1000) {
        self$tracker$step <- -self$tracker$step
      }
    }
  )
)

SequenceController <- R6Class("SequenceController",
  public = list(
    tracker = NULL,
    analyzer = NULL,
    
    initialize = function(tracker, analyzer) {
      self$tracker <- tracker
      self$analyzer <- analyzer
    },
    
    run = function() {
      while (TRUE) {
        self$analyzer$analyze()
        self$tracker$advance()
      }
    }
  )
)

main <- function() {
  tracker <- SequenceTracker$new(0, 10)
  analyzer <- SequenceAnalyzer$new(tracker)
  controller <- SequenceController$new(tracker, analyzer)
  controller$run()
}

main()