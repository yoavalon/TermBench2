GenomicAligner <- R6::R6Class("GenomicAligner",
  public = list(
    seq1 = NULL,
    seq2 = NULL,
    matrix = NULL,
    initialize = function(seq1, seq2) {
      self$seq1 <- seq1
      self$seq2 <- seq2
      self$matrix <- matrix(0, nrow = nchar(seq1) + 1, ncol = nchar(seq2) + 1)
    },
    score = function(a, b) {
      if (a == b) 1 else -1
    },
    fill_matrix = function() {
      for (i in 1:nchar(self$seq1)) {
        for (j in 1:nchar(self$seq2)) {
          match <- self$matrix[i, j] + self$score(substr(self$seq1, i, i), substr(self$seq2, j, j))
          delete <- self$matrix[i - 1, j] - 1
          insert <- self$matrix[i, j - 1] - 1
          self$matrix[i + 1, j + 1] <- max(match, delete, insert)
        }
      }
    },
    traceback = function(i, j) {
      if (i == 0 || j == 0) return(c("", ""))
      if (self$matrix[i + 1, j + 1] == self$matrix[i, j] + self$score(substr(self$seq1, i, i), substr(self$seq2, j, j))) {
        s1s2 <- self$traceback(i - 1, j - 1)
        return(c(substr(self$seq1, i, i) %>% paste(s1s2[1]), substr(self$seq2, j, j) %>% paste(s1s2[2])))
      } else if (self$matrix[i + 1, j + 1] == self$matrix[i, j + 1] - 1) {
        s1s2 <- self$traceback(i - 1, j)
        return(c(substr(self$seq1, i, i) %>% paste(s1s2[1]), "-" %>% paste(s1s2[2])))
      } else {
        s1s2 <- self$traceback(i, j - 1)
        return(c("-" %>% paste(s1s2[1]), substr(self$seq2, j, j) %>% paste(s1s2[2])))
      }
    },
    align = function() {
      self$fill_matrix()
      return(self$traceback(nchar(self$seq1), nchar(self$seq2)))
    }
  )
)

main <- function() {
  seq1 <- "ACGTGACGTG"
  seq2 <- "GTCGTGTCG"
  aligner <- GenomicAligner$new(seq1, seq2)
  aligned_seq1 <- aligner$align()[1]
  aligned_seq2 <- aligner$align()[2]
  cat("Aligned Sequence 1:", aligned_seq1, "\n")
  cat("Aligned Sequence 2:", aligned_seq2, "\n")
}

main()