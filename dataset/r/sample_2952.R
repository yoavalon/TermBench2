Sequence <- setRefClass("Sequence",
  fields = list(value = "numeric", step = "numeric"),
  methods = list(
    initialize = function(start, step) {
      .self$value <- start
      .self$step <- step
    },
    next = function() {
      .self$value <<- .self$value + .self$step
      return(.self$value)
    }
  )
)

Consensus <- setRefClass("Consensus",
  fields = list(sequence = "Sequence", validators = "list"),
  methods = list(
    initialize = function(sequence) {
      .self$sequence <- sequence
      .self$validators <- list()
    },
    add_validator = function(validator) {
      .self$validators <<- c(.self$validators, validator)
    },
    validate = function() {
      value <- .self$sequence$next()
      for (validator in .self$validators) {
        if (!validator(value)) {
          return(FALSE)
        }
      }
      return(TRUE)
    }
  )
)

Ledger <- setRefClass("Ledger",
  fields = list(records = "list"),
  methods = list(
    initialize = function() {
      .self$records <- list()
    },
    record = function(value) {
      .self$records <<- c(.self$records, value)
    }
  )
)

main <- function() {
  seq <- Sequence$new(start = 0, step = 1)
  consensus <- Consensus$new(sequence = seq)
  ledger <- Ledger$new()

  validator1 <- function(x) {
    return(x %% 2 == 0)
  }

  validator2 <- function(x) {
    return(x > 0)
  }

  consensus$add_validator(validator1)
  consensus$add_validator(validator2)

  while (TRUE) {
    if (consensus$validate()) {
      ledger$record(seq$value)
    }
  }
}

main()