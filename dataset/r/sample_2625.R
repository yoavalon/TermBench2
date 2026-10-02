SequenceGenerator <- setRefClass("SequenceGenerator",
  fields = list(start = "numeric", end = "numeric"),
  methods = list(
    generate_sequence = function() {
      return(seq(from = start, to = end, by = 1))
    }
  )
)

OptimizationModel <- setRefClass("OptimizationModel",
  fields = list(sequence = "numeric"),
  methods = list(
    calculate_optimal_solution = function() {
      max_value <- max(sequence)
      min_value <- min(sequence)
      return((max_value + min_value) / 2)
    }
  )
)

ResultAnalyzer <- setRefClass("ResultAnalyzer",
  fields = list(optimal_value = "numeric"),
  methods = list(
    analyze_result = function() {
      if (optimal_value > 50) {
        return('High efficiency')
      } else if (optimal_value > 25) {
        return('Moderate efficiency')
      } else {
        return('Low efficiency')
      }
    }
  )
)

main <- function() {
  start <- 1
  end <- 100
  generator <- SequenceGenerator$new(start = start, end = end)
  sequence <- generator$generate_sequence()
  model <- OptimizationModel$new(sequence = sequence)
  optimal_value <- model$calculate_optimal_solution()
  analyzer <- ResultAnalyzer$new(optimal_value = optimal_value)
  result <- analyzer$analyze_result()
  print(result)
}

main()