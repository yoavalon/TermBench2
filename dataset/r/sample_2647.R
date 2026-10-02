library(stats)

SequenceProcessor <- setRefClass("SequenceProcessor",
  fields = list(sequence = "numeric", length = "numeric"),
  methods = list(
    initialize = function(sequence) {
      .self$sequence <<- sequence
      .self$length <<- length(sequence)
    },
    process = function() {
      transformed <- .self$transform_sequence()
      return(.self$analyze(transformed))
    },
    transform_sequence = function() {
      transformed <- numeric(.self$length)
      for (i in 1:.self$length) {
        value <- .self$sequence[i]
        transformed[i] <<- sin(value) * cos(value)
      }
      return(transformed)
    },
    analyze = function(sequence) {
      analysis <- numeric(length(sequence))
      for (i in 1:length(sequence)) {
        analysis[i] <<- round(sequence[i], 4)
      }
      return(analysis)
    }
  )
)

generate_sequence <- function(n) {
  sequence <- numeric(n)
  for (i in 1:n) {
    sequence[i] <<- sqrt(i)
  }
  return(sequence)
}

main <- function() {
  n <- 10
  sequence <- generate_sequence(n)
  processor <- SequenceProcessor$new(sequence)
  result <- processor$process()
  print(result)
}

main()