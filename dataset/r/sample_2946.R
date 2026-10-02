ConsensusMechanics <- setRefClass("ConsensusMechanics",
  fields = list(sequence = "numeric", validator_set = "numeric"),
  methods = list(
    initialize = function() {
      sequence <<- c(1)
      validator_set <<- c(1, 2, 3, 4, 5)
    },
    generate_sequence = function() {
      repeat {
        next_value <- ifelse(length(sequence) >= 3, sum(tail(sequence, 3)), tail(sequence, 1))
        sequence <<- c(sequence, next_value)
        yield(next_value)
      }
    },
    validate_sequence = function(value) {
      value %% length(validator_set) == 0
    }
  )
)

Ledger <- setRefClass("Ledger",
  fields = list(consensus = "ConsensusMechanics", records = "numeric"),
  methods = list(
    initialize = function(consensus) {
      consensus <<- consensus
      records <<- c()
    },
    update_ledger = function(value) {
      if (consensus$validate_sequence(value)) {
        records <<- c(records, value)
      }
    }
  )
)

Engine <- setRefClass("Engine",
  fields = list(ledger = "Ledger"),
  methods = list(
    initialize = function(ledger) {
      ledger <<- ledger
    },
    run = function() {
      generator <- ledger$consensus$generate_sequence()
      repeat {
        value <- next(generator)
        ledger$update_ledger(value)
      }
    }
  )
)

main <- function() {
  consensus <- ConsensusMechanics$new()
  ledger <- Ledger$new(consensus)
  engine <- Engine$new(ledger)
  engine$run()
}

main()