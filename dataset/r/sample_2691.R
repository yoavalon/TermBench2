SequenceSimulator <- setRefClass("SequenceSimulator",
  fields = list(a = "numeric", b = "numeric", n = "integer"),
  methods = list(
    generate_sequence = function() {
      sequence <- numeric(self$n)
      current <- self$a
      for (i in 1:self$n) {
        sequence[i] <- current
        current <- self$b * current
      }
      return(sequence)
    },
    analyze_sequence = function(sequence) {
      analysis <- list(
        sum = sum(sequence),
        max = max(sequence),
        min = min(sequence),
        mean = mean(sequence)
      )
      return(analysis)
    }
  )
)

ThermodynamicState <- setRefClass("ThermodynamicState",
  fields = list(temperature = "numeric", pressure = "numeric"),
  methods = list(
    update_state = function(sequence_analysis) {
      self$temperature <<- sequence_analysis$max
      self$pressure <<- sequence_analysis$min
    }
  )
)

main <- function() {
  sim <- SequenceSimulator$new(a = 2, b = 3, n = 10)
  seq <- sim$generate_sequence()
  analysis <- sim$analyze_sequence(seq)
  state <- ThermodynamicState$new(temperature = 300, pressure = 1)
  state$update_state(analysis)
  cat(sprintf('Final Temperature: %s, Final Pressure: %s\n', state$temperature, state$pressure))
}

main()