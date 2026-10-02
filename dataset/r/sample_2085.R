Sequencer <- R6::R6Class("Sequencer",
  public = list(
    sequence = NULL,
    length = NULL,
    initialize = function(sequence) {
      self$sequence <- sequence
      self$length <- length(sequence)
    },
    align = function(other) {
      score <- 0
      for (i in 1:min(self$length, other$length)) {
        if (self$sequence[i] == other$sequence[i]) {
          score <- score + 1
        }
      }
      return(score)
    },
    normalize = function() {
      return(as.numeric(self$sequence) / self$length)
    }
  )
)

Aligner <- R6::R6Class("Aligner",
  public = list(
    sequences = NULL,
    sequencers = NULL,
    initialize = function(sequences) {
      self$sequences <- sequences
      self$sequencers <- lapply(sequences, function(seq) Sequencer$new(seq))
    },
    pairwise_alignment = function() {
      scores <- c()
      for (i in 1:length(self$sequencers)) {
        for (j in (i + 1):length(self$sequencers)) {
          score <- self$sequencers[[i]]$align(self$sequencers[[j]])
          scores <- c(scores, score)
        }
      }
      return(scores)
    },
    average_score = function() {
      total <- sum(self$pairwise_alignment())
      return(total / length(self$sequencers))
    }
  )
)

main <- function() {
  sequences <- list('ATCG', 'ATCC', 'ATCGT', 'ATCGA')
  aligner <- Aligner$new(sequences)
  average_score <- aligner$average_score()
  normalized_scores <- lapply(aligner$sequencers, function(seq) seq$normalize())
  cat('Average Alignment Score: ', average_score, '\n')
  for (i in 1:length(normalized_scores)) {
    cat('Normalized Sequence ', i, ': ', normalized_scores[[i]], '\n')
  }
}

main()