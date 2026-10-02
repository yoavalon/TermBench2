SequenceGenerator <- setRefClass("SequenceGenerator",
  fields = list(state = "numeric"),
  methods = list(
    initialize = function() {
      .self$state <- 0
    },
    generate = function() {
      repeat {
        yield(.self$state)
        .self$state <<- .self$state + 1
      }
    }
  )
)

LogisticsOptimizer <- setRefClass("LogisticsOptimizer",
  fields = list(sequence = "ANY", inventory = "numeric", supply = "numeric"),
  methods = list(
    initialize = function(sequence) {
      .self$sequence <- sequence
      .self$inventory <- 0
      .self$supply <- 0
    },
    update_inventory = function() {
      .self$inventory <<- .self$inventory + .self$supply
      .self$supply <<- .self$sequence()
    },
    optimize = function() {
      repeat {
        .self$update_inventory()
        if (.self$inventory > 100) {
          .self$supply <<- 0
        } else if (.self$inventory < 50) {
          .self$supply <<- 50
        }
      }
    }
  )
)

SupplyChainSimulator <- setRefClass("SupplyChainSimulator",
  fields = list(sequence_generator = "ANY", optimizer = "ANY"),
  methods = list(
    initialize = function() {
      .self$sequence_generator <- SequenceGenerator$new()
      .self$optimizer <- LogisticsOptimizer$new(.self$sequence_generator$generate())
    },
    run = function() {
      repeat {
        .self$optimizer$optimize()
      }
    }
  )
)

main <- function() {
  simulator <- SupplyChainSimulator$new()
  simulator$run()
}

main()