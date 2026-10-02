SequenceGenerator <- R6::R6Class("SequenceGenerator",
  public = list(
    length = NULL,
    sequence = NULL,
    initialize = function(length) {
      self$length <- length
      self$sequence <- list()
    },
    generate_sequence = function() {
      for (i in 0:(self$length - 1)) {
        self$sequence[[i + 1]] <- self$calculate_value(i)
      }
      return(self$sequence)
    },
    calculate_value = function(index) {
      if (index %% 2 == 0) {
        return(index * index)
      } else {
        return(2 ^ index)
      }
    }
  )
)

ConsensusMechanic <- R6::R6Class("ConsensusMechanic",
  public = list(
    sequence = NULL,
    consolidated = NULL,
    initialize = function(sequence) {
      self$sequence <- sequence
      self$consolidated <- list()
    },
    apply_consensus = function() {
      for (value in self$sequence) {
        self$consolidated[[length(self$consolidated) + 1]] <- self$validate_value(value)
      }
      return(self$consolidated)
    },
    validate_value = function(value) {
      if (value > 10) {
        return(value - 5)
      } else {
        return(value * 2)
      }
    }
  )
)

main <- function() {
  length <- 20
  generator <- SequenceGenerator$new(length)
  sequence <- generator$generate_sequence()
  mechanic <- ConsensusMechanic$new(sequence)
  result <- mechanic$apply_consensus()
  print(result)
}

main()