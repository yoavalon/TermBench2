SequenceMatcher <- R6::R6Class("SequenceMatcher",
  public = list(
    seq1 = NULL,
    seq2 = NULL,
    len1 = NULL,
    len2 = NULL,
    
    initialize = function(seq1, seq2) {
      self$seq1 <- seq1
      self$seq2 <- seq2
      self$len1 <- nchar(seq1)
      self$len2 <- nchar(seq2)
    },
    
    match = function() {
      matrix <- matrix(0, nrow = self$len1 + 1, ncol = self$len2 + 1)
      for (i in 1:self$len1) {
        for (j in 1:self$len2) {
          if (substr(self$seq1, i, i) == substr(self$seq2, j, j)) {
            matrix[i + 1, j + 1] <- matrix[i, j] + 1
          } else {
            matrix[i + 1, j + 1] <- max(matrix[i, j + 1], matrix[i + 1, j])
          }
        }
      }
      return(matrix[self$len1 + 1, self$len2 + 1])
    }
  )
)

GenomicSequenceAnalyzer <- R6::R6Class("GenomicSequenceAnalyzer",
  public = list(
    sequences = NULL,
    
    initialize = function(sequences) {
      self$sequences <- sequences
    },
    
    analyze = function() {
      results <- list()
      for (i in 1:(length(self$sequences) - 1)) {
        for (j in (i + 1):length(self$sequences)) {
          matcher <- SequenceMatcher$new(self$sequences[i], self$sequences[j])
          results[[length(results) + 1]] <- list(idx1 = i, idx2 = j, score = matcher$match())
        }
      }
      return(results)
    }
  )
)

main <- function() {
  sequences <- c('ATCGTACG', 'CGTACGTA', 'GTAATCGC', 'TACGTACG', 'ACGTACGT')
  analyzer <- GenomicSequenceAnalyzer$new(sequences)
  results <- analyzer$analyze()
  for (res in results) {
    cat(sprintf('Sequence %d vs Sequence %d: Alignment Score %d\n', res$idx1, res$idx2, res$score))
  }
}

main()