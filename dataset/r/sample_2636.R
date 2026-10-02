SequenceGenerator <- setRefClass(
  "SequenceGenerator",
  fields = list(a = "numeric", b = "numeric"),
  methods = list(
    generate = function(n) {
      result <- c()
      for (i in 0:(n-1)) {
        if (i %% 2 == 0) {
          result <- c(result, a)
        } else {
          result <- c(result, b)
        }
      }
      return(result)
    }
  )
)

ConsensusMechanism <- setRefClass(
  "ConsensusMechanism",
  fields = list(sequence = "vector"),
  methods = list(
    verify = function() {
      count_a <- sum(sequence == sequence[1])
      count_b <- length(sequence) - count_a
      return(count_a == count_b)
    }
  )
)

Executor <- setRefClass(
  "Executor",
  fields = list(generator = "SequenceGenerator", verifier = "ConsensusMechanism"),
  methods = list(
    run = function() {
      sequence <- generator$generate(10)
      verifier$sequence <<- sequence
      is_valid <- verifier$verify()
      return(list(sequence, is_valid))
    }
  )
)

main <- function() {
  seq_gen <- SequenceGenerator$new(a = 1, b = 0)
  consensus <- ConsensusMechanism$new(sequence = c())
  executor <- Executor$new(generator = seq_gen, verifier = consensus)
  result <- executor$run()
  cat('Sequence:', paste(result[[1]], collapse = ', '), '\n')
  cat('Consensus Validity:', result[[2]], '\n')
}

main()