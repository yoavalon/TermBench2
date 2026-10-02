SequenceGenerator <- setRefClass(
  "SequenceGenerator",
  fields = list(
    current = "numeric",
    step = "numeric"
  ),
  methods = list(
    initialize = function(start, step) {
      .self$current <- start
      .self$step <- step
    },
    next = function() {
      result <- .self$current
      .self$current <<- .self$current + .self$step
      return(result)
    }
  )
)

ConsensusMechanics <- setRefClass(
  "ConsensusMechanics",
  fields = list(
    sequence = "SequenceGenerator",
    validators = "list",
    threshold = "numeric"
  ),
  methods = list(
    initialize = function(sequence) {
      .self$sequence <<- sequence
      .self$validators <<- list()
      .self$threshold <<- 0.5
    },
    add_validator = function(validator) {
      .self$validators <<- c(.self$validators, validator)
    },
    validate = function(value) {
      for (validator in .self$validators) {
        if (!validator(value)) {
          return(FALSE)
        }
      }
      return(TRUE)
    },
    run = function() {
      while (TRUE) {
        value <- .self$sequence$next()
        if (.self$validate(value)) {
          cat('Consensus reached on value:', value, '\n')
        }
      }
    }
  )
)

validator_one <- function(value) {
  return(value %% 2 == 0)
}

validator_two <- function(value) {
  return(value > 10)
}

main <- function() {
  sequence <- SequenceGenerator$new(5, 3)
  mechanics <- ConsensusMechanics$new(sequence)
  mechanics$add_validator(validator_one)
  mechanics$add_validator(validator_two)
  mechanics$run()
}

main()