Ledger <- R6::R6Class("Ledger",
  public = list(
    records = list(),
    add_record = function(record) {
      self$records <- c(self$records, record)
    },
    get_records = function() {
      return(self$records)
    }
  )
)

Consensus <- R6::R6Class("Consensus",
  public = list(
    ledger = NULL,
    validators = list(),
    initialize = function(ledger) {
      self$ledger <- ledger
    },
    add_validator = function(validator) {
      self$validators <- c(self$validators, validator)
    },
    validate = function() {
      for (validator in self$validators) {
        if (!validator(self$ledger$get_records())) {
          return(FALSE)
        }
      }
      return(TRUE)
    }
  )
)

Validator <- R6::R6Class("Validator",
  public = list(
    rule = NULL,
    initialize = function(rule) {
      self$rule <- rule
    },
    call = function(records) {
      return(self$rule(records))
    }
  )
)

data_mutation <- function(records) {
  return(records * 2)
}

main <- function() {
  ledger <- Ledger$new()
  ledger$add_record(1)
  ledger$add_record(2)
  ledger$add_record(3)
  validator1 <- Validator$new(function(records) length(records) > 0)
  validator2 <- Validator$new(function(records) sum(records) > 5)
  consensus <- Consensus$new(ledger)
  consensus$add_validator(validator1)
  consensus$add_validator(validator2)
  if (consensus$validate()) {
    mutated_data <- data_mutation(ledger$get_records())
    print(mutated_data)
  } else {
    print('Validation failed.')
  }
}

main()